public class Main {
    public static void main(String[] args) {
        char[] s = "hello".toCharArray();
        int n = s.length;

        // 직접 swap
        for (int i = 0; i < n / 2; i++) {
            char temp = s[i];
            s[i] = s[n - i - 1];
            s[n - i - 1] = temp;
        }

        System.out.println(new String(s));  // "olleh"
    }
}
