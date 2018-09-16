package dictionary;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class Dictionary {
    public static enum Words{
    csc210("Intro to Java","To learn Java","Comfortable with Objects and Classes","Ready for CSC 220"),
    csc220("Data Structures","Ready to create complexe data structures","To create data structures"),
    csc340("C++ version of CSC210 + CSC220 + more","A CS upper division course","Many hours outside of class"),
    book("A set of pages", "To arrange something on a particular date"),
    bookable("Can be ordered"),
    bookbinder("A person who fastens the pages of books"),
    bookcase("A piece of furniture with shelves");
    //datafield
    private  String d1;
    private  String d2;
    private  String d3;
    private  String d4; 
    //k is number of definitions
    private Integer k;
   //Constructors
    private Words(String d1,String d2,String d3,String d4){
    this.d1=d1;
    this.d2=d2;
    this.d3=d3;
    this.d4=d4;
    this.k = 4;
    }
    private Words(String d1,String d2,String d3){
    this.d1=d1;
    this.d2=d2;
    this.d3=d3;
    this.k=3;
    }
    private Words(String d1,String d2){
    this.d1=d1;
    this.d2=d2;
    this.k=2;
    }
    private Words(String d1){
    this.d1=d1;
    this.k=1;
    }
    //Getters
    public String getd1(){
        return d1;
    }
    public String getd2(){
        return d2;
    }
    public String getd3(){
        return d3;
    }
    public String getd4(){
        return d4;
    }
    public Integer k(){
        return k;
    }
    @Override 
    public String toString(){
        if (this.k==1){return this.name() + " : " + this.d1 + "\n";}
        else if (this.k==2){return this.name() + " : " + this.d1 + "\n" + this.name() + " : " + this.d2 +"\n";}
        else if (this.k==3){return this.name() + " : " + this.d1 + "\n" + this.name() + " : " + this.d2 + "\n"+this.name() + " : " + this.d3 + "\n";}
        else if (this.k==4){return this.name() + " : " + this.d1 + "\n" + this.name() + " : " + this.d2 + "\n"+this.name() + " : " + this.d3 + "\n" +this.name() + " : " + this.d4 + "\n" ;}
    return null;        
        }
    }
   
    public static Map<String,Integer> dictionary;
    public static Scanner type = new Scanner(System.in);
    
     public Dictionary(){ 
        dictionary = new HashMap<String,Integer>();
     }
     
     public void uploadData(){
        for (int i =0; i<Words.values().length;i++) {
        dictionary.put(Words.values()[i].name(), i);
        }  
     }
     
     public void processData(){
      System.out.println("-----Dictionary 340 Standard--------\n\n");
      String lookup="";
      
      while(true){
      System.out.print("Search:  ");
      lookup = type.nextLine();
      if(lookup.equals("!q")){System.out.println("Bye Felicia!");break;}
      else{
      boolean k = false;
      for (Entry <String, Integer> entry : dictionary.entrySet()) {
          String key = entry.getKey();
          Integer index = entry.getValue();
               if (lookup.toLowerCase().equals(key)){
                   k = true;
                   System.out.printf("%s",Words.values()[index].toString() );
                   System.out.print("\n");
               }     
      }
      if (k==false){ System.out.println("NOT FOUND");}
     }}
     }    
    public static void main(String[] args) {
     Dictionary mydic = new Dictionary();
     mydic.uploadData();
     mydic.processData();
      
    }
}
