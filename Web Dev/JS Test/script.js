const fakeRequest = (url) => {
    return new Promise((resolve, reject) => {
        const delay = Math.floor(Math.random() * 4500) + 500;
        setTimeout(() => {
            if (delay > 2000) {
                reject("Connection timeout");
            } else {
                resolve(`Here is your fake data from ${url}`);
            }
        }, delay);
    })
}

async function make2Requests() {
    try {
        let data1 = await fakeRequest('/page1');
        console.log(data1);
        let data2 = await fakeRequest('/page2');
        console.log(data2);
    } catch (e) {
        console.log(`Error: ${e}`);
    }
};

make2Requests();

/* ----------------------------------- */

const login = async (username, password) => {
    if (!username || !password) {
        throw 'Missing credintials';
    } else if (password === 'hooblaKaala') {
        return 'Welcome Beyotch';
    }
    throw 'Invalid Password';
}

login('noobFuck', 'hoobla-Kaala')
    .then(msg => {
        console.log("Logged In");
        console.log(msg);
    })
    .catch(err => {
        console.log("Error!!");
        console.log(err);
    });