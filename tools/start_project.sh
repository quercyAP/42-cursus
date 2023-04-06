#!/bin/bash

echo "Entrez le nom du projet:"
read project_name

if [ -d "$project_name" ]; then
    echo "Erreur: Un projet avec le même nom existe déjà."
    exit 1
fi

echo "Entrez le langage du projet (c, cpp, autre):"
read language

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
        ;;
    "autre")
        echo "Entrez les noms des dossiers à créer (séparés par des espaces):"
        read -a dirs
        mkdir $project_name
        for dir in "${dirs[@]}"; do
            mkdir $project_name/$dir
        done
        ;;
    *)
        echo "Langage non pris en charge"
        exit 1
        ;;
esac

echo "Le projet $project_name a été créé avec succès!"
