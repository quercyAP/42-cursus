// Sélectionner le bloc main-content
var mainContent = document.querySelector('.main-content');

var scale = 1.0;
var scalingUp = false;

// Écouter l'événement de mouvement de la souris
mainContent.addEventListener('mousemove', function(e) {
    var rect = mainContent.getBoundingClientRect();  // Récupérer les coordonnées de l'élément par rapport à la fenêtre
    var x = (e.clientX - rect.left - rect.width / 2) / 30;  // Ajuster le dénominateur pour augmenter la sensibilité
    var y = (e.clientY - rect.top - rect.height / 2) / 30; // Ajuster le dénominateur pour augmenter la sensibilité

    mainContent.style.transform = 'scale(' + scale + ') translate(' + x + 'px, ' + y + 'px)';
});

// Réinitialiser la transformation lorsque la souris quitte le bloc
mainContent.addEventListener('mouseleave', function() {
    mainContent.style.transform = 'none';
    scalingUp = false;
});

// Augmenter progressivement l'échelle lorsque la souris entre dans le bloc
mainContent.addEventListener('mouseenter', function() {
    scalingUp = true;
    var intervalId = setInterval(function() {
        if (scale < 1.1 && scalingUp) {
            scale += 0.01
            // Appliquer l'échelle
            mainContent.style.transform = 'scale(' + scale + ')';
        } else if (scale > 1.0 && !scalingUp) {
            scale -= 0.001;
            // Appliquer l'échelle
            mainContent.style.transform = 'scale(' + scale + ')';
        } else {
            // Arrêter l'intervalle lorsque l'échelle a atteint 1.1 ou est retombée à 1.0
            clearInterval(intervalId);
        }
    }, 10);  // Délai entre chaque augmentation de l'échelle
});

// Commencer à réduire l'échelle lorsque la souris quitte le bloc
mainContent.addEventListener('mouseleave', function() {
    scalingUp = false;
    scale = 1.0;
});
