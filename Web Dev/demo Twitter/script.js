const tweetForm = document.querySelector('#tweetForm');
const tweetContainer = document.querySelector('#tweets');

tweetForm.addEventListener('submit', (e) => {
    e.preventDefault();
    const usernameInput = tweetForm.elements.username;
    const tweetInput = tweetForm.elements.tweet;
    addTweet(username.value, tweet.value);

    usernameInput.value = '';
    tweetInput.value = '';
})

const addTweet = (username, tweet) => {
    const newTweet = document.createElement('li');
    const boldTag = document.createElement('b');
    const deleteLabel = document.createElement('label');
    deleteLabel.innerText = '[X]';
    deleteLabel.style.color = 'red'
    boldTag.append(username);
    newTweet.append(boldTag);
    newTweet.append(` - ${tweet} `);
    newTweet.append(deleteLabel);
    tweetContainer.append(newTweet);

}

tweetContainer.addEventListener('click', (e) => {
    if (e.target.nodeName === 'LABEL') {
        e.target.parentElement.remove();
    }
})