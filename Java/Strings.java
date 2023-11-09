public class Strings {

    public static void main(String[] args) {

        String s = "We realizes that while our workers were thriving, the surrounding villages were still suffering. It became our goal to uplift their quality of life as well. I remember seeing a family of 4 on a motorbike in the heavy Bombay rain — I knew I wanted to do more for these families who were risking their lives for lack of an alternative.The alternative mentioned here is the Tata Nano, which soon after came as the world’s cheapest car on retail at a starting price of only Rs 1 lakh. These were the words of Ratan Tata in a recent post by Humans of Bombay which formed the basis of his decision to come up with a car like Tata Nano.";

        System.out.println();
        System.out.println(s.charAt(67));

        String s1 = s.substring(3, 10);
        String s2 = s.substring(27, 31);
        System.out.println(s1);
        System.out.println(s2);

        System.out.println(s1.compareTo(s2));

        System.out.println(s1.concat(s2));
        System.out.println(s.contains("realizes"));

        System.out.println(s.endsWith("Nano."));

        System.out.println(s1.equals(s2));
        System.out.println(s1.equalsIgnoreCase(s2));

        String s3 = String.format("I %s", s1);
        System.out.println(s3);

        System.out.println(s1.getBytes());

        String str = "motorbike in the heavy Bombay rain";

        char[] destArray = new char[20];
        str.getChars(13, 22, destArray, 0);
        System.out.println(destArray);

        System.out.println(s.indexOf(s1));

        // intern()
        String s5 = s.intern();
        System.out.println(s5);

        // isEmpty()
        System.out.println(s.isEmpty());

        // join()
        String str1 = String.join("-", "We", "have", "an", "assignment");
        System.out.println(str1);

        // lastIndexOf()
        System.out.println(str1.lastIndexOf("have"));

        // length()
        System.out.println(str1.length());

        // replace()
        str1 = str1.replace("We", "I");
        System.out.println(str1);

        // replaceAll()
        String s6 = str1.replaceAll("e", "a");
        System.out.println(s6);

        // split()
        String[] s7 = str1.split("-");

        for (String a : s7) {
            System.out.println(a);
        }

        // Starts With
        System.out.println(str1);
        System.out.println(str1.startsWith("I-have"));

        // Substring()

        String str5 = s.substring(50, 90);
        System.out.println(str5);

        // tochararray()
        char[] arr = s.toCharArray();
        System.out.println(arr);

        // toLowerCase()
        System.out.println(s1.toLowerCase());

        // toUpperCase()
        System.out.println(s1.toUpperCase());

        // trim()
        String s9 = "    Trim Example    ";
        System.out.println(s9.trim());

        // valueOf()
        int value = 30;
        String s10 = String.valueOf(value);
        System.out.println(s10 + 10);

    }
}