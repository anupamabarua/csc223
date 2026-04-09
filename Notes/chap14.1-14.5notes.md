# Chapter 14: Searching and Sorting — Notes (Sections 14.1–14.5)
## 14.1 Introduction to Searching
### Definition
Searching means determining whether a specific value exists in an array.  
- If found → successful search → returns the position  
- If not found → unsuccessful search → displays a message  
### Key Points
- Choice of algorithm depends on how data is organized:
  - Unsorted data → Linear Search  
  - Sorted data → Binary Search (more efficient)  
- Searching is a fundamental operation in computer science  
## 14.2 Linear Search (Sequential Search)
### Definition
A simple method that checks each element one-by-one until a match is found.
### How It Works
1. Start at the first element  
2. Compare each element with the target value (VAL)  
3. If match found → return position  
4. If end reached with no match → value not present  
### Characteristics
- Works on unsorted arrays  
- No preprocessing required  
### Time Complexity
- Best case: O(1) → value at first position  
- Worst case: O(n) → value at last position or not present  
### Key Insight
Simple but inefficient for large datasets  
## 14.3 Binary Search
### Definition
A search algorithm that works on sorted arrays by repeatedly dividing the search space in half.
### How It Works
1. Set:
   - BEG = start index  
   - END = last index  
2. Compute:
   - MID = (BEG + END) / 2  
3. Compare A[MID] with VAL:
   - If equal → found  
   - If VAL < A[MID] → search left half  
   - If VAL > A[MID] → search right half  
4. Repeat until found or BEG > END  
### Requirements
- Array must be sorted  
### Time Complexity
- O(log n)  
### Key Insight
Much faster than linear search because it eliminates half the data each step  
## 14.4 Interpolation Search
### Definition
A search algorithm for sorted arrays that estimates the likely position of the target value.
### How It Works
- Instead of checking the middle, it estimates position using value distribution  
- Then:
  - If match → done  
  - Otherwise → reduce search space accordingly  
### Characteristics
- Works best when data is uniformly distributed  
### Time Complexity
- Average case: O(log log n)  
- Worst case: O(n)  
### Key Insight
More efficient than binary search for evenly distributed data  
## 14.5 Jump Search
### Definition
A search algorithm for sorted arrays that skips ahead in blocks instead of checking every element.
### How It Works
1. Choose step size:
   - Typically √n  
2. Jump ahead in blocks:
   - Compare last element of block with VAL  
3. Once a block containing VAL is found:
   - Perform linear search within that block  
### Time Complexity
- O(√n)  
### Advantages
- Faster than linear search for sorted arrays  
- Useful when backward movement is costly  
### Key Insight
Hybrid approach:
- Jumping narrows the range  
- Linear search finds the exact position  
## Summary Comparison

| Algorithm        | Requires Sorted Data | Time Complexity    | Key Idea                    |
|-----------------|---------------------|-------------------|-----------------------------|
| Linear Search   | No                  | O(n)              | Check every element         |
| Binary Search   | Yes                 | O(log n)          | Divide in half              |
| Interpolation   | Yes                 | O(log log n) avg  | Estimate position           |
| Jump Search     | Yes                 | O(√n)             | Jump in blocks              |