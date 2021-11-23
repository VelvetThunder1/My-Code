public class GeneralizedHarmonic {
	public static void main(String[] args) {
		int n = Integer.parseInt(args[0]);
		int r = Integer.parseInt(args[1]);
		double H = 0;
		for (int i = 1; i < n + 1; i++) {
			H  = ((1/(Math.pow(i,r))) + H);
		}
		System.out.println(H);
	}
}
