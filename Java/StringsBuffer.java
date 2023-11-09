
public class StringsBuffer {
    public static void main(String[] args) {
        
        StringBuffer str = new StringBuffer("Christ ");
        System.out.println();
        //append()
        str.append("University");
        System.out.println(str);

        //insert()
        System.out.println(str.insert(17,"Bangalore"));   

        //replace()
        System.out.println(str.replace(17, 26,"Kengeri"));

        //delete()
        System.out.println(str.delete(17, 26));

        //charAt
        System.out.println(str.charAt(15));

        //setCharAt()
        str.setCharAt(16, 'Y');
        System.out.println(str);

        //length()
        System.out.println(str.length());

        // capacity() method
        int capacity = str.capacity();
        System.out.println(capacity);

        // ensureCapacity() method
        str.ensureCapacity(50);
        System.out.println(str.capacity());

        // toString() method
        String str1 = str.toString();
        System.out.println(str1);

        // substring(int start) method
        String subStr1 = str.substring(7);
        System.out.println(subStr1);

        // substring(int start, int end) method
        String subStr2 = str.substring(0, 6);
        System.out.println(subStr2);

    }
}
