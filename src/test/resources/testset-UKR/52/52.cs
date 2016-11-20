
п»їusing System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows;

namespace Lab_1
{
    class Type
    {
        public int num1 { get; set; }
        public int num2 { get; set; }
    }

    class FileSystem
    {
        public static string openFileName { get; set; }
        public static List<Type> fullList { get; set; }
        public static List<int> ListOfInt { get; set; }
        public static List<int> Uniq      { set; get; }

        public static void OpenTextFile(string name)
        {
            fullList    = new List<Type>();
            ListOfInt   = new List<int>();
            Uniq        = new List<int>();

            using (var file = new StreamReader(name))
            {
                string str;
                file.ReadLine();
                while((str = file.ReadLine()) != null)
                {
                    Type tmp = new Type();
                    tmp.num1 = int.Parse(str.Split(new char[] { ' ' })[0]);
                    tmp.num2 = int.Parse(str.Split(new char[] { ' ' })[1]);

                    ListOfInt.Add(int.Parse(str.Split(new char[] { ' ' })[0]));
                    ListOfInt.Add(int.Parse(str.Split(new char[] { ' ' })[1]));
                    
                    fullList.Add(tmp);
                }
            }
            List<int> uniq = new List<int>(ListOfInt.Distinct());
            uniq.Sort();

            ListOfInt.Clear();
            ListOfInt.AddRange(uniq);
            Uniq.AddRange(uniq);

            openFileName = name;
            GenerationList();

        }

        private static void GenerationList()
        {
            Type firstPair = fullList[0];
        }
    }
}
