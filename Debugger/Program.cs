using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Debugger
{
    class Program
    {
        static void Main(string[] args)
        {
            EventWaitHandle Gate = new EventWaitHandle(true, EventResetMode.ManualReset);
            long Count = 0;
            Gate.Reset();

            List<Task> Tasks = new List<Task>();

            for (int I = 0; I < 100_000; I++)
            {
                Tasks.Add(Task.Run(() =>
                {
                    System.Threading.Interlocked.Add(ref Count, 1);
                    Console.WriteLine("Count: {0}", Count);
                    Gate.WaitOne();
                    System.Threading.Interlocked.Add(ref Count, -1);
                }));
            }

            System.Threading.Thread.Sleep(1000);
            Gate.Set();

            Console.WriteLine("Count: {0}", Count);
            Console.ReadKey();
        }
    }
}
