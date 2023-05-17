#include <exiv2/exiv2.hpp>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include "../include/tabulate/single_include/tabulate/tabulate.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Veuillez fournir au moins un fichier en argument." << std::endl;
        return -1;
    }

    Exiv2::LogMsg::setLevel(Exiv2::LogMsg::mute);

    for (int i = 1; i < argc; ++i) {
        try {
            Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(argv[i]);
            assert(image.get() != 0);
            image->readMetadata();

            Exiv2::ExifData &exifData = image->exifData();
            if (exifData.empty()) {
                std::string error(argv[i]);
                error += ": Aucune métadonnée EXIF trouvée dans le fichier";
                throw Exiv2::Error(Exiv2::kerErrorMessage, error);
            }

            std::cout << "Metadata pour " << argv[i] << ":\n";

            tabulate::Table table;
            table.add_row({"Clé", "Tag", "Type", "Nombre", "Valeur"});

            Exiv2::ExifData::const_iterator end = exifData.end();
            for (Exiv2::ExifData::const_iterator i = exifData.begin(); i != end; ++i) {
                const char* tn = i->typeName();
                std::string key = i->key();
                std::string tag = "0x" + std::to_string(i->tag());
                std::string type = tn ? tn : "Unknown";
                std::string count = std::to_string(i->count());
                std::string value = i->toString();

                table.add_row({key, tag, type, count, value});
            }

            std::cout << table << std::endl;
        }
        catch (Exiv2::AnyError& e) {
            std::cout << "Erreur : " << e << "\n";
        }
    }
    return 0;
}
