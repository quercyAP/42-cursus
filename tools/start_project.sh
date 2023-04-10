#!/bin/bash

RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
BLUE="\033[0;34m"
NC="\033[0m"

echo -e "${BLUE}Entrez le nom du projet:${NC}"
read project_name

if [ -d "$project_name" ]; then
    echo -e "${RED}Erreur: Un projet avec le même nom existe déjà.${NC}"
else
    echo -e "${BLUE}Entrez le langage du projet (c, cpp, autre):${NC}"
    read language

    feature() {
        case $language in
            "c")
                cp /Users/glamazer/Desktop/42-cursus/tools/makefile_pattern/makec $project_name/Makefile
                ;;
            "cpp")
                cp /Users/glamazer/Desktop/42-cursus/tools/makefile_pattern/makecpp $project_name/Makefile
                ;;
            "autre")
                # Ajoutez d'autres cas pour d'autres langages si nécessaire
                ;;
        esac
    }

    case $language in
        "c"|"cpp")
            mkdir $project_name
            mkdir $project_name/src
            mkdir $project_name/include
            mkdir $project_name/obj
            if [ "$language" == "c" ]; then
                touch $project_name/src/main.c
            else
                touch $project_name/src/main.cpp
            fi
            feature
            ;;
        "autre")
            echo -e "${BLUE}Entrez les noms des dossiers à créer (séparés par des espaces):${NC}"
            read -a dirs
            mkdir $project_name
            for dir in "${dirs[@]}"; do
                mkdir $project_name/$dir
            done
            feature
            ;;
        *)
            echo -e "${RED}Langage non pris en charge${NC}"
            exit 1
            ;;
    esac

    echo -e "${GREEN}Le projet $project_name a été créé avec succès!${NC}"

fi

