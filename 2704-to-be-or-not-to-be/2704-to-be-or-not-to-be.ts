type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};

const expect = (val: any): ToBeOrNotToBe => ({
    toBe: (otherVal) => {
        if (otherVal === val) return true;
        throw "Not Equal";
    },
    notToBe: (otherVal) => {
        if (otherVal !== val) return true;
        throw "Equal";
    }
});