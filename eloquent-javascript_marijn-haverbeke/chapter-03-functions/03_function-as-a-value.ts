let launchMissiles = function () {
    console.log("now");
};

let safeMode = true;

if (safeMode) {
    launchMissiles = function () {};
}
