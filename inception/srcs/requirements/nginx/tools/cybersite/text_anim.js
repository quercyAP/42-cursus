var mainContent = document.querySelector('.main-content');

var scale = 1.0;
var scalingUp = false;

mainContent.addEventListener('mousemove', function(e) {
    var rect = mainContent.getBoundingClientRect();
    var x = (e.clientX - rect.left - rect.width / 2) / 20;
    var y = (e.clientY - rect.top - rect.height / 2) / 20;

    mainContent.style.transform = 'scale(' + scale + ') translate(' + x + 'px, ' + y + 'px)';
});

mainContent.addEventListener('mouseleave', function() {
    mainContent.style.transform = 'none';
    scalingUp = false;
});

mainContent.addEventListener('mouseenter', function() {
    scalingUp = true;
    var intervalId = setInterval(function() {
        if (scale < 1.1 && scalingUp) {
            scale += 0.01
            mainContent.style.transform = 'scale(' + scale + ')';
        } else if (scale > 1.0 && !scalingUp) {
            scale -= 0.001;
            mainContent.style.transform = 'scale(' + scale + ')';
        } else {0
            clearInterval(intervalId);
        }
    }, 10);
});

mainContent.addEventListener('mouseleave', function() {
    scalingUp = false;
    scale = 1.0;
});
