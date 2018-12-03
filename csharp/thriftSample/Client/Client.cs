using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Thrift.Protocol;
using Thrift.Transport;

namespace Client
{
    class Client
    {
        static void Main(string[] args)
        {
            TTransport transport = new TSocket("localhost", 9090);
            TProtocol protocol = new TBinaryProtocol(transport);
            Sample.Client client = new Sample.Client(protocol);

            transport.Open();
            try
            {
                string hello = client.hello("World");
                Console.WriteLine(hello);

                string ipaddr = client.ipaddr();
                Console.WriteLine(ipaddr);

                int random = client.random(5);
                Console.WriteLine(random);

                string uuid = client.uuid();
                Console.WriteLine(uuid);

                Calc calc = client.calculator(5, 7);
                Console.WriteLine(calc);
            }
            catch (SampleException e)
            {
                Console.WriteLine(e.StackTrace);
            }

            transport.Close();

            Console.ReadKey();
        }
    }
}
