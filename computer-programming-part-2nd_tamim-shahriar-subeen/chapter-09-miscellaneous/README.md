# অধ্যায় ০৯ - বিবিধ

## ৯.১ - কনস্ট্যান্ট(constant), ম্যাক্রো (Macro) এবং টার্নারি অপারেটর
1. constant using #define
2. macro using #define
3. টার্নারি অপারেটর `কন্ডিশন? স্টেটমেন্ট 1 : স্টেটমেন্ট 2` | কন্ডিশন যদি সত্য হয়, তাহলে স্টেটমেন্ট 1 কাজ করবে, আর সত্য না হলে স্টেটমেন্ট ২

## ৯.২ - এনিউমারেশন (enumeration)
1. `enum`
2. `switch` statement

## ৯.3 - কমান্ড লাইন আর্গুমেন্ট (Command Line Argument)
1. `int argc, char *argv[]` argument in main() function
2. convert str into int use `atoi()` function

## ৯.৪ - প্রোগ্রাম কম্পাইল হওয়ার ধাপসমূহ
1. সি প্রোগ্রাম কম্পাইল হওয়ার সময় মোট চারটি কাজ হয়:
   1. প্রিপ্রসেসিং (Preprocessing)
   2. কম্পাইল (Compile)
   3. অ্যাসেম্বলি (Assembly)
   4. লিঙ্কিং (Linking)
2. Preprocesser: Preprocesser remove comments and include header files in source code, replace macro name with code.
3. Compiler: Compiler generate assembly code .
4. Assembler: Assembler conbert assemble code into object code or binary code.
5. Linker: Linker combine all the object code and make one executable code (in window `.exe` or linux `a.out`)

## ৯.৫ - typedef ও #define নিয়ে কিছু কথা
1. `#define` is preprocesser
2. `typedef` is a keyword
3. typedef  অন্যান্য ভ্যারিয়েবলের মতো স্কোপিং নীতি মেনে চলে যেখানে #define এর কােনো স্কোপিং নীতি নেই। যেখানে ডিফাইন করা হয় তার পরে থেকে যেকোনো জায়গায় ব্যবহার করা যায়।

## ৯.৬ - main() ফাংশন ও return 0
1. ISO C90 অনুসারে এই তিনটি উপায়ে main() ফাংশন ডিক্লেয়ার করা যাবে
   ```c
   int main(void)
   int main(int argc, char **argv)
   int main(int argc, char *argb[])
   ```
2. main() ফাংশন return করার আদর্শ নীতিমালা
   ```c
   0
   EXIT_SUCCESS
   EXIT_FAILURE
   ```
3. ISO C99 আদর্শ নীতিমালা অনুসারে
   1. main() ফাংশনের ডিক্লেয়ারেশনে int শব্দটি অবশ্যই উল্লেখ করতে হবে।
   2. return 0  কথাটি চাইলে বাদ দেওয়া যাবে। যদি এই লাইনটি না লেখা হয় ডিফল্ট হিসেবে main() ফাংশন এক্সিকিউশনের শেষে 0 রিটির্ন করা হবে।
4. main() ফাংশন return করার আর্দশ নিয়ম
   1. প্রোগ্রাম ঠিকভাবে চলে এক্সিট করলে 0 রিটার্ন করা
   2. প্রােগ্রাম চলাকালে কোনো এরর হয়ে যদি প্রোগ্রামটি মধ্যপথেই বন্ধ হয়ে যায় তাহলে, 0 ছাড়া যেকোন মান রিটার্ন করা।

## ৯.৭ - lvalue এবং rvalue
1. এক্সপ্রেশন লিখতে হলে সমান চিহ্নের বামে যে অংশটি থাকে বলে এলভ্যালু (lvalue)
2. এক্সপ্রেশন লিখতে হলে সমান চিহ্নের ডানে যে অংশটি থাকে বলে আরভ্যালু (lvalue)
3. এলভ্যালু সেই সব এক্সপ্রেশন যাদের একটি মেমোরি লোকেশন থাকে এবং সেই লোকেশনের কোনো একটি মানকে অ্যাসাইন করা যায়। এদের যেহেতু মেমোরি লোকেশন থাকে সেহেতু এদের একটি মানও থাকে।
4. আরভ্যালু হচ্ছে সেই সয় এক্সেপ্রেশন যাদের একটি মান থাকে। এদেরও একটি মেমোরি লোকেশন থাকে, কেননা সব মানই তো কোনো না কোনো মেমোরি লোকেশনেই আছে। তবে এই মেমোরি লোকেশন কোনো ভ্যারিয়েবলকে নির্দেশ করে না এবং এখানে কোনো মান অ্যাসাইন করা যায় না।
