import java.util.*;

public class greedy_plus_or_multiply {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();

        // 첫 번째 문자를 숫자로 변경한 값을 대입
        long result = str.charAt(0) - '0';
        for (int i = 1; i <str.length(); i++) {
            int num = str.charAt(i) - '0';
            if (num <= 1 || result <= 1) {
                result +=  num;
            }
            else {
                result *= num;
            }
        }
        System.out.println(result);
    }
}
