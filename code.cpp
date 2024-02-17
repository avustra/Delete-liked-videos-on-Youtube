function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

async function deleteLikedVideos() {
  'use strict';

  const items = document.querySelectorAll('ytd-menu-renderer > yt-icon-button.dropdown-trigger > button[aria-label]');
  
  for (let i = 0; i < items.length; i++) {
    const item = items[i];
    item.click();

    const out = setTimeout(() => {
      const lastElement = document.querySelector('tp-yt-paper-listbox.style-scope.ytd-menu-popup-renderer').lastElementChild;
      if (lastElement) {
        lastElement.click();
      }
    }, 100);

    await sleep(500); // sleep because the browser may not handle the process well
    clearTimeout(out);
  }
}

deleteLikedVideos();
