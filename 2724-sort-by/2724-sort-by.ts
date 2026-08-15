type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Fn = (value: JSONValue) => number

function sortBy(arr: JSONValue[], fn: Fn): JSONValue[] {
        function swap(a: any, b: any): number {
        return (fn(a) < fn(b)) ? -1 : 1;
    }

    return arr.sort(swap);
};