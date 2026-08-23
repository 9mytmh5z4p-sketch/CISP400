// slides.js - Custom JavaScript for CISP 400 Presentations

// ===== Keyboard Mappings =====
window.Reveal.on('ready', event => {
  Reveal.configure({
    keyboard: {
      34: 'down',      // Forward button
      33: 'up',        // Back button
      116: 'right',    // Start/Play button
      190: 'left'      // Black Screen button
    }
  });
});

// ===== Progressive Code Highlighting =====
function highlightLine(lineNumber) {
  const line = document.querySelector(`.line-${lineNumber}`);
  if (line) {
    line.classList.add('highlight-line');
  }
}

// ===== Variable Tracker =====
function updateVariableDisplay(variables) {
  const display = document.getElementById('variable-tracker');
  if (display) {
    display.innerHTML = Object.entries(variables)
      .map(([name, value]) => `${name} = ${value}`)
      .join('<br>');
  }
}

// ===== Timer for Exercises =====
function startTimer(minutes, elementId) {
  let seconds = minutes * 60;
  const timerElement = document.getElementById(elementId);
  
  const interval = setInterval(() => {
    const mins = Math.floor(seconds / 60);
    const secs = seconds % 60;
    timerElement.textContent = `${mins}:${secs.toString().padStart(2, '0')}`;
    
    if (seconds === 0) {
      clearInterval(interval);
      timerElement.textContent = "Time's up!";
      timerElement.classList.add('timer-expired');
    }
    seconds--;
  }, 1000);
}

// ===== Confetti Effect =====
function showConfetti() {
  // Using canvas-confetti library
  confetti({
    particleCount: 100,
    spread: 70,
    origin: { y: 0.6 }
  });
}

// ===== Code Execution Simulator =====
let executionStep = 0;
let codeSteps = [];

function initCodeSimulator(steps) {
  codeSteps = steps;
  executionStep = 0;
}

function executeNextStep() {
  if (executionStep < codeSteps.length) {
    const step = codeSteps[executionStep];
    highlightLine(step.line);
    updateVariableDisplay(step.variables);
    executionStep++;
  }
}

// ===== Interactive Quiz =====
function checkAnswer(questionId, selectedAnswer, correctAnswer) {
  const feedback = document.getElementById(`feedback-${questionId}`);
  
  if (selectedAnswer === correctAnswer) {
    feedback.textContent = '✓ Correct!';
    feedback.className = 'feedback-correct';
    showConfetti();
    
    // Auto-advance after 2 seconds
    setTimeout(() => Reveal.next(), 2000);
  } else {
    feedback.textContent = '✗ Try again!';
    feedback.className = 'feedback-incorrect';
    
    // Shake effect
    feedback.classList.add('shake');
    setTimeout(() => feedback.classList.remove('shake'), 500);
  }
}

// ===== Slide Bookmarks =====
function toggleBookmark(slideIndex) {
  let bookmarks = JSON.parse(localStorage.getItem('cisp400-bookmarks')) || [];
  
  if (bookmarks.includes(slideIndex)) {
    bookmarks = bookmarks.filter(b => b !== slideIndex);
  } else {
    bookmarks.push(slideIndex);
  }
  
  localStorage.setItem('cisp400-bookmarks', JSON.stringify(bookmarks));
  updateBookmarkIcon(slideIndex);
}

function updateBookmarkIcon(slideIndex) {
  const bookmarks = JSON.parse(localStorage.getItem('cisp400-bookmarks')) || [];
  const icon = document.querySelector(`.bookmark-icon[data-slide="${slideIndex}"]`);
  
  if (icon) {
    icon.textContent = bookmarks.includes(slideIndex) ? '★' : '☆';
  }
}

// ===== Auto-pause videos when leaving slide =====
Reveal.on('slidechanged', event => {
  // Pause all videos on slide change
  document.querySelectorAll('video').forEach(video => video.pause());
});

// ===== Dark mode toggle =====
function toggleDarkMode() {
  document.body.classList.toggle('dark-mode');
  const isDark = document.body.classList.contains('dark-mode');
  localStorage.setItem('cisp400-theme', isDark ? 'dark' : 'light');
}

// Load saved theme preference
window.addEventListener('DOMContentLoaded', () => {
  const savedTheme = localStorage.getItem('cisp400-theme');
  if (savedTheme === 'dark') {
    document.body.classList.add('dark-mode');
  }
});

// ===== Progress Tracker =====
Reveal.on('slidechanged', event => {
  const current = Reveal.getIndices().h + 1;
  const total = Reveal.getTotalSlides();
  const percentage = Math.round((current / total) * 100);
  
  const tracker = document.getElementById('progress-tracker');
  if (tracker) {
    tracker.textContent = `Slide ${current} of ${total} (${percentage}%)`;
  }
});