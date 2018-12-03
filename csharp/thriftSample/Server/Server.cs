using System;
using System.Net;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Thrift.Server;
using Thrift.Protocol;
using Thrift.Transport;

namespace Server
{
    public class SampleHandler : Sample.Iface
    {
        Calc calc;

        public string hello(string value)
        {
            Console.WriteLine("Client.hello(\"{0}\")", value);

            return "Hello " + value + " :)";
        }

        public string ipaddr()
        {
            Console.WriteLine("Client.ipaddr()");

            string hn = Dns.GetHostName();
            IPHostEntry addrentry = Dns.GetHostEntry(hn);
            if (addrentry.AddressList.Any())
            {
                IPAddress addr = addrentry.AddressList.First();
                return addr.ToString();
            }

            throw new SampleException
            {
                Code = ErrorCode.INVALID_IPADDR,
                Reason = "Invalid IP Address"
            };
        }

        public int random(int num)
        {
            Console.WriteLine("Client.random({0})", num);

            if (num == 0)
            {
                throw new SampleException
                {
                    Code = ErrorCode.INVALID_NUMERIC,
                    Reason = "Too few digits"
                };
            }

            if (num > 5)
            {
                throw new SampleException
                {
                    Code = ErrorCode.INVALID_NUMERIC,
                    Reason = "Too many digits"
                };
            }

            int x, y;
            x = (int)Math.Pow(10, (num - 1));
            y = (int)Math.Pow(10, num);

            Random rnd = new System.Random();
            return rnd.Next(x, y);
        }

        public string uuid()
        {
            Console.WriteLine("Client.uuid()");

            Guid guid = Guid.NewGuid();
            return guid.ToString();
        }

        public Calc calculator(double num1, double num2)
        {
            Console.WriteLine("Client.calculator({0}, {1})", num1, num2);

            if (num1 == 0 && num2 == 0)
            {
                throw new SampleException
                {
                    Code = ErrorCode.INVALID_NUMERIC,
                    Reason = "Too few number"
                };
            }


            this.calc = new Calc
            {
                Plus = num1 + num2,
                Minus = num1 - num2,
                Multiplies = num1 * num2,
                Divides = num1 / num2
            };

            return this.calc;
        }
    }

    public class Server
    {
        public static void Main(string[] args)
        {
            try
            {
                SampleHandler handler = new SampleHandler();
                Sample.Processor processor = new Sample.Processor(handler);
                TServerTransport serverTransport = new TServerSocket(9090);
                TServer server = new TSimpleServer(processor, serverTransport);

                Console.WriteLine("Starting the server...");
                server.Serve();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.StackTrace);
            }
        }
    }
}
