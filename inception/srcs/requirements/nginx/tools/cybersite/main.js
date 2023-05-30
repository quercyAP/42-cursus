var cybersecurityTips = [
    "Utilisez toujours des mots de passe forts",
    "Mettez régulièrement à jour vos logiciels",
    "Ne cliquez pas sur des liens douteux",
];

function loadTips() {
    var tipsElement = document.getElementById("tips");

    for (var i = 0; i < cybersecurityTips.length; i++) {
        var listItem = document.createElement("li");
        listItem.textContent = cybersecurityTips[i];
        tipsElement.appendChild(listItem);
    }
}

window.onload = loadTips;
