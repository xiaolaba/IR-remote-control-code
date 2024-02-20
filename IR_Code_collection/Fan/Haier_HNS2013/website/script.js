function playAudio(audioFileName) {

  var audio = new Audio(audioFileName);
  audio.play();

/*}
    var audio = document.getElementById(audioFileName);
  if (audio) {
    audio.play();
  } else {
    console.error("Audio element not found.");
  }
*/  
  
/*
// Remove the information div after a few seconds
setTimeout(function() {
  var infoDiv = document.getElementById('info');
  infoDiv.parentNode.removeChild(infoDiv);
}, 5000); // 5000 milliseconds = 5 seconds
*/

}

