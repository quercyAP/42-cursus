#!/bin/bash

if [ ! -d "/goinfre/$USER/.brew" ]; then
  # install homebrew
  echo "###### INSTALLING HOMEBREW ######"
  curl -fsSL https://raw.githubusercontent.com/omimouni/42homebrew/master/install-goinfre.sh | zsh
  echo ""
fi


# install vscode
echo "###### INSTALLING VSCODE ######"
VSCODE_VERSION=$(curl -s https://formulae.brew.sh/api/cask/visual-studio-code.json | jq .version -r)
curl -L https://update.code.visualstudio.com/$VSCODE_VERSION/darwin/stable -o ~/goinfre/vscode.zip
unzip ~/goinfre/vscode.zip -d ~/goinfre
rm ~/goinfre/vscode.zip
xattr -dr com.apple.quarantine ~/goinfre/Visual\ Studio\ Code.app
mkdir ~/goinfre/code-portable-data
echo ""


#install valgrind
echo "###### INSTALLING VALGRIND ######"
brew tap LouisBrunner/valgrind
brew install --HEAD LouisBrunner/valgrind/valgrind
echo ""

#install readline 
echo "###### INSTALLING  READLINE  #####"
brew install readline

#shell preference Custom shell /bin/zsh --login