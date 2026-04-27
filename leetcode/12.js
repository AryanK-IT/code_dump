/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function (num) {
    const value = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
    const symbol = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"];

    let roman = '';
    for (let i = 0; i < value.length; i++) {
        while (num >= value[i]) {
            roman += symbol[i];
            num -= value[i];
        }
    }
    return roman;
};