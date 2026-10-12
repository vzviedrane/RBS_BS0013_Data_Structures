# Week 6 Reflection — Linear-Probing Hash Map

Answer briefly after your implementation works.

1. Under suitable hashing and controlled load, why are lookup, insertion, and deletion described as **expected Θ(1)** rather than worst-case Θ(1)?
Because collisions can happen, and sometimes we may need to check many slots. With good hashing and a reasonable load factor, we usually check only a few slots.
2. Give a set of integer keys that all collide when the table capacity is 7. What happens to their probe lengths?
Keys 10, 17, and 24 all start at index 3 because they have the same remainder when divided by 7. Their probe lengths are 1, 2, and 3.
3. Why must lookup continue through a Deleted slot but may stop at an Empty slot?
A Deleted slot might have other keys after it, so we need to keep searching. An Empty slot means the key was never placed further along that seacrh path.
4. Why must insert_or_assign continue probing after finding a tombstone before deciding to insert there?
Because the same key might already exist later in the table. We need to check before inserting to avoid duplicate keys.
5. Why does increasing the load factor usually increase successful and unsuccessful probe lengths?
Because there are fewer empty slots, so collisions become more common and we need to check more positions.
6. Why can changing the table capacity require reinserting or rehashing every live key?
Because the bucket position depends on the capacity. When the capacity changes, keys may need diffrent positions.
7. How is **expected Θ(1)** hash-table lookup different from **amortized Θ(1)** dynamic-array append?
Expected Θ(1) depends on good hashing and the distribution of keys. Amortized Θ(1) means most appends are fast, while occasional resizing costs more, but the average cost over many appends stays constant.
8. Give one tradeoff between separate chaining and open addressing.
Separate chaining uses extra memory for linked nodes but handles collisions without filling the main table. Open addressing stores elements directly in the table but can have longer searches when the table gets full.
