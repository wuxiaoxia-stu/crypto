using System;
using Netca.Pki;

namespace GenRandom
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 1)
            {
                Console.WriteLine("Usage: GenRandom length");
                return;
            }

            int len = int.Parse(args[0]);
            byte[] data=Util.GenerateRandom(len);
            Console.WriteLine(BitConverter.ToString(data).Replace("-", ""));
            
        }
    }
}
