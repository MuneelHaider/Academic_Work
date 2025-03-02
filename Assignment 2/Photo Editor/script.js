/*

Muneel Haider
i21-0640

Web Development - Assignment 2

*/

var fileInput = document.querySelector(".file-input");
var chooseImage = document.querySelector(".choose-img");
var saveImage = document.querySelector(".save-img");
var resetFilters = document.querySelector(".reset-filter");
var image = document.querySelector(".preview-img img");

var brightness = document.getElementById("brightness");
var saturation = document.getElementById("saturation");
var inversion = document.getElementById("inversion");
var grayscale = document.getElementById("grayscale");

var leftRotateButton = document.getElementById("left");
var rightRotateButton = document.getElementById("right");
var horizontalFlipButton = document.getElementById("horizontal");
var verticalFlipButton = document.getElementById("vertical");

var filterSlider = document.querySelector(".slider input");
var filterName = document.querySelector(".filter-info .name");
var filterValue = document.querySelector(".filter-info .value");

// default values
var brightnessValue = 100;
var saturationValue = 100;
var inversionValue = 0;
var grayscaleValue = 0;
var rotationValue = 0;
var horizontalFlipValue = 1;
var verticalFlipValue = 1;

// this function applys filter to preview image
function applyFiltersToImage() {
    image.style.filter = 
        "brightness(" + brightnessValue + "%) " +
        "saturate(" + saturationValue + "%) " +
        "invert(" + inversionValue + "%) " +
        "grayscale(" + grayscaleValue + "%)";
    
    image.style.transform = 
        "rotate(" + rotationValue + "deg) " +
        "scale(" + horizontalFlipValue + ", " + verticalFlipValue + ")";
}

// updates the filters value on slider change
function updateFilterValue() {
    filterValue.innerText = filterSlider.value + "%";

    if (filterName.innerText === "Brightness") {
        brightnessValue = filterSlider.value;
    } else if (filterName.innerText === "Saturation") {
        saturationValue = filterSlider.value;
    } else if (filterName.innerText === "Inversion") {
        inversionValue = filterSlider.value;
    } else if (filterName.innerText === "Grayscale") {
        grayscaleValue = filterSlider.value;
    }

    applyFiltersToImage();
}

// brightness filter is selected
brightness.onclick = function() {
    filterName.innerText = "Brightness";
    filterSlider.max = 200;
    filterSlider.value = brightnessValue;
    filterValue.innerText = brightnessValue + "%";
};

// saturation filter is selected
saturation.onclick = function() {
    filterName.innerText = "Saturation";
    filterSlider.max = 200;
    filterSlider.value = saturationValue;
    filterValue.innerText = saturationValue + "%";
};

// inversion filter is selected
inversion.onclick = function() {
    filterName.innerText = "Inversion";
    filterSlider.max = 100;
    filterSlider.value = inversionValue;
    filterValue.innerText = inversionValue + "%";
};

// grayscale filter is selected
grayscale.onclick = function() {
    filterName.innerText = "Grayscale";
    filterSlider.max = 100;
    filterSlider.value = grayscaleValue;
    filterValue.innerText = grayscaleValue + "%";
};

filterSlider.oninput = updateFilterValue;

// button that rotates the image to left
leftRotateButton.onclick = function() {
    rotationValue -= 90;
    applyFiltersToImage();
};

// button that rotates the image to right
rightRotateButton.onclick = function() {
    rotationValue += 90;
    applyFiltersToImage();
};

// button that flips the image horizontally
horizontalFlipButton.onclick = function() {
    horizontalFlipValue *= -1;
    applyFiltersToImage();
};

// button that flips the image vertically
verticalFlipButton.onclick = function() {
    verticalFlipValue *= -1;
    applyFiltersToImage();
};

// loads image from users device
fileInput.onchange = function(event) {
    var selectedFile = event.target.files[0];
    if (selectedFile) {
        image.src = URL.createObjectURL(selectedFile);
    }
};

// opens the file selector for uploading image
chooseImage.onclick = function() {
    fileInput.click();
};

// saves edited image
saveImage.onclick = function() {
    var canvasElement = document.createElement("canvas");
    var canvasContext = canvasElement.getContext("2d");

    canvasElement.width = image.naturalWidth;
    canvasElement.height = image.naturalHeight;

    canvasContext.filter = image.style.filter;
    canvasContext.translate(canvasElement.width / 2, canvasElement.height / 2);
    canvasContext.scale(horizontalFlipValue, verticalFlipValue);
    canvasContext.rotate((rotationValue * Math.PI) / 180);
    canvasContext.drawImage(image, -canvasElement.width / 2, -canvasElement.height / 2, canvasElement.width, canvasElement.height);

    var downloadLink = document.createElement("a");
    downloadLink.download = "edited-image.png";
    downloadLink.href = canvasElement.toDataURL();
    downloadLink.click();
};

// sets all filters back to default values (as chosen above)
resetFilters.onclick = function() {
    brightnessValue = 100;
    saturationValue = 100;
    inversionValue = 0;
    grayscaleValue = 0;
    rotationValue = 0;
    horizontalFlipValue = 1;
    verticalFlipValue = 1;
    applyFiltersToImage();
};
