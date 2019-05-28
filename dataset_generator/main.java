import java.util.concurrent.ThreadLocalRandom;
import java.io.PrintWriter;

public class main
{
    public static void main(String args[])
    {
        int min = -1000000;
        int max = 1000000;
        int N = 100000;
        try {
            PrintWriter writer = new PrintWriter("big_data.txt", "UTF-8");
            writer.println(N);
    
            for(int i=0;i<N;i++) {
                int randomNum = ThreadLocalRandom.current().nextInt(min, max + 1);
                writer.println(randomNum);
            }
            writer.close();
        }
        catch(Exception e) {
            System.err.println("ERROR");
        }
    }
}