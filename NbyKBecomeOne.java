import java.util.Scanner;

public class NbyKBecomeOne {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int K = scanner.nextInt();

        int result = 0;

        while (true) {
            int target = (N / K ) * K;
            result += (N - target);
            N = target;

            if (N < K) {
                break;
            }

            result++;
            N /= K;
        }

        result += (N - 1);

        System.out.println(result);

        scanner.close();
    }
}
