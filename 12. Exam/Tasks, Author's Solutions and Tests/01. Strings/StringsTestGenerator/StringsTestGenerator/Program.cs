using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using RandomExtensions;

namespace StringsTestGenerator
{
    class Program
    {
        static Random random = new Random();

        static void Main(string[] args)
        {
            GenerateTest("test.001", 3, 5, 8);
            GenerateTest("test.002", 1, 5, 8);
            GenerateTest("test.003", 8, 1, 2);
            GenerateTest("test.004", 10, 0, 2);
            GenerateTest("test.005", 50, 0, 8);

            GenerateTest("test.006", 30, 1, 80);
            GenerateTest("test.007", 0, 0, 0);
            GenerateTest("test.008", 80, 1, 2);
            GenerateTest("test.009", 10, 0, 2);
            GenerateTest("test.010", 100, 0, 100);
        }

        static void GenerateTest(string name, int stringsCount, int minLength, int maxLength)
        {
            List<string> strings = random.NextN(stringsCount, () => random.NextWord(random.Next(minLength, maxLength), 0)).ToList();

            List<sbyte> bytes = new List<sbyte>();
            bytes.Add((sbyte)stringsCount);

            foreach (var s in strings)
            {
                bytes.AddRange(SerializeString(s));
            }

            System.IO.File.WriteAllText(name + ".in.txt", string.Join(" ", bytes.ToArray()) + System.Environment.NewLine);
            System.IO.File.WriteAllText(name + ".out.txt", string.Join(System.Environment.NewLine, strings) + System.Environment.NewLine);
        }

        static List<sbyte> SerializeString(string s)
        {
            if (s.Length > sbyte.MaxValue)
            {
                throw new ArgumentException("s.Length too large: " + s.Length);
            }

            List<sbyte> bytes = new List<sbyte>();

            bytes.Add((sbyte)s.Length);
            bytes.AddRange(s.Select(c => (sbyte)c).ToList());

            return bytes;
        }
    }
}

namespace RandomExtensions
{
    class Pair<T>
    {
        public T First { get; set; }
        public T Second { get; set; }
        public Pair(T first, T second)
        {
            this.First = first;
            this.Second = second;
        }
    }

    static class RandomExtensions
    {
        const string Vowels = "aeiouwy";
        const string Consonants = "bcdfghjklmnpqrstvwxz";

        public static List<T> NextN<T>(this Random r, int count, Func<T> generator)
        {
            List<T> unique = new List<T>();

            while (unique.Count < count)
            {
                unique.Add(generator.Invoke());
            }

            return unique;
        }

        public static HashSet<T> NextUniqueN<T>(this Random r, int count, Func<T> generator)
        {
            HashSet<T> unique = new HashSet<T>();

            while (unique.Count < count)
            {
                unique.Add(generator.Invoke());
            }

            return unique;
        }

        public static string NextUrl(this Random random)
        {
            return "http://" + random.NextWord(random.Next(3, 10), 0) + "." + random.NextWord(3, 0);
        }

        public static string NextWord(this Random r, int length, double capitalsChance)
        {
            StringBuilder word = new StringBuilder();

            while (word.Length < length)
            {
                string source;
                if (word.Length == 0)
                {
                    source = r.NextChance(0.5) ? Vowels : Consonants;
                }
                else if (Vowels.Contains(word[word.Length - 1]))
                {
                    source = r.NextChance(0.8) ? Consonants : Vowels;
                }
                else
                {
                    source = r.NextChance(0.8) ? Vowels : Consonants;
                }

                word.Append(source[r.Next(0, source.Length)]);
            }

            for (int i = 0; i < word.Length; i++)
            {
                word[i] = r.NextChance(capitalsChance) ? char.ToUpper(word[i]) : word[i];
            }

            return word.ToString();
        }

        public static bool NextChance(this Random r, double probability)
        {
            // NOTE: 0 probability is always false (min NextDouble() is 0, 0 < 0 is false) and 1 probability is always true (NextDouble() always returns less than 1)
            return r.NextDouble() < probability;
        }

        public static List<int> NextIncreasingOrEqualInRange(this Random r, int length, Pair<int> rangeInclusive)
        {
            List<int> values = new List<int>();
            while (values.Count < length)
            {
                values.Add(r.Next(values.Count > 0 ? values[values.Count - 1] : rangeInclusive.First, rangeInclusive.Second + 1));
            }

            return new List<int>(values);
        }

        public static List<int> NextStrictlyIncreasingInRange(this Random r, int length, Pair<int> rangeInclusive)
        {
            int rangeElementsCount = (rangeInclusive.Second - rangeInclusive.First) + 1;
            if (rangeElementsCount < length)
            {
                throw new ArgumentException("rangeInclusive does not contain enough values to generate required length");
            }

            SortedSet<int> values = new SortedSet<int>();
            while (values.Count < length)
            {
                values.Add(r.Next(rangeInclusive.First, rangeInclusive.Second + 1));
            }

            return new List<int>(values);
        }

        public static void NextShuffle<T>(this Random r, List<T> list)
        {
            for (int repeats = 0; repeats < 10; repeats++)
            {
                for (int i = 0; i < list.Count; i++)
                {
                    int otherInd = r.Next(0, list.Count);
                    var swap = list[i];
                    list[i] = list[otherInd];
                    list[otherInd] = swap;
                }
            }
        }

        public static int NextIndex<T>(this Random r, ICollection<T> range)
        {
            return r.Next(0, range.Count);
        }

        public static T NextFrom<T>(this Random r, List<T> from)
        {
            return from[NextIndex(r, from)];
        }

        public static List<int> NextIntegersFrom(this Random r, int count, List<int> from)
        {
            List<int> integers = new List<int>();

            while (integers.Count < count)
            {
                integers.Add(NextFrom(r, from));
            }

            return integers;
        }

        public static List<int> NextIntegers(this Random r, int count)
        {
            return NextIntegersExcluding(r, count, new HashSet<int>());
        }

        public static List<int> NextIntegersExcluding(this Random r, int count, HashSet<int> excluded)
        {
            List<int> integers = new List<int>();

            while (integers.Count < count)
            {
                integers.Add(NextExcluding(r, excluded));
            }

            return integers;
        }

        public static int NextExcluding(this Random r, HashSet<int> excluded)
        {
            int value = r.Next();
            while (excluded.Contains(value))
            {
                value = r.Next();
            }

            return value;
        }
    }
}
