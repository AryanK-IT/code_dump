/**
 * @param {number} x
 * @return {number}
 */
var reverse = function (x) {
    

    var isNegative = x < 0;
    x = Math.abs(x);

    var temp = 0;
    const length = x.toString().length;
    var i = 0;

    while (i < length) {
        temp = temp * 10 + x % 10;
        x = Math.floor(x / 10);
        i++;
    }

    if (isNegative) {
        temp = -temp;
    }

    if (temp < -(2 ** 31) || temp > 2 ** 31 - 1) {
        return 0;
    }
    return temp;
};