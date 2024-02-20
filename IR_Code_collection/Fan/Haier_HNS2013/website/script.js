function playAudio(audioFileName) {
  var audio = new Audio(audioFileName);
  audio.play();

// Remove the information div after a few seconds
setTimeout(function() {
  var infoDiv = document.getElementById('info');
  infoDiv.parentNode.removeChild(infoDiv);
}, 5000); // 5000 milliseconds = 5 seconds

}

