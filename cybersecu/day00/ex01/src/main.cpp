#include <exiv2/exiv2.hpp>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Veuillez fournir au moins un fichier en argument." << std::endl;
        return -1;
    }

    Exiv2::LogMsg::setLevel(Exiv2::LogMsg::mute);  // désactive les avertissements

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
            Exiv2::ExifData::const_iterator end = exifData.end();
            for (Exiv2::ExifData::const_iterator i = exifData.begin(); i != end; ++i) {
                const char* tn = i->typeName();
                std::cout << std::setw(44) << std::setfill(' ') << std::left
                          << i->key() << " "
                          << "0x" << std::setw(4) << std::setfill('0') << std::right
                          << std::hex << i->tag() << " "
                          << std::setw(9) << std::setfill(' ') << std::left
                          << (tn ? tn : "Unknown") << " "
                          << std::dec << std::setw(3)
                          << std::setfill(' ') << std::right
                          << i->count() << "  "
                          << std::dec << i->value()
                          << "\n";
            }
        }
        catch (Exiv2::AnyError& e) {
            std::cout << "Erreur : " << e << "\n";
            return -1;
        }
    }
    return 0;
}
