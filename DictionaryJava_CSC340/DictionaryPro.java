package dictionary;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Dictionary {

	// Here I create a HashMap with keys as subjects, and values as hashmaps
	// containing each form of speech belonging to the subject and definition associated
	// with it
	public static HashMap<String, HashMap<String, String>> words;

	public static Scanner type = new Scanner(System.in);

	public Dictionary() {
		// I populate the Hashmap inline, no need to create a lot of variable because I
		// won't be needing the variable itself but only the contents of it aka :
		// the suject, the form of speech and their def
		words = new HashMap<String, HashMap<String, String>>() {
			{
				put("csc210", new HashMap<String, String>() {
					{
						put("Intro to Java", "noun");
						put("To learn Java", "verb");
						put("Comfortable with Objects and Classe", "adjective");
						put("Ready for CSC 220", "noun");
					}
				});
				put("csc220", new HashMap<String, String>() {
					{
						put("Data Structures", "noun");
						put("Ready to create complexe data structures", "noun");
						put("To create data structures", "verb");
					}
				});
				put("csc340", new HashMap<String, String>() {
					{
						put("C++ version of CSC210 + CSC220 + more", "noun");
						put("A CS upper division course", "verb");
						put("Many hours outside of class", "adjective");
					}
				});
				put("book", new HashMap<String, String>() {
					{
						put("A set of pages", "noun");
						put("To arrange something on a particular date", "verb");
					}
				});
				put("bookable", new HashMap<String, String>() {
					{
						put("Can be ordered", "verb");
					}
				});
				put("bookbinder", new HashMap<String, String>() {
					{
						put("A person who fastens the pages of books", "noun");
					}
				});
				put("bookcase", new HashMap<String, String>() {
					{
						put("A piece of furniture with shelves", "noun");
					}
				});
			}
		};
	}


	public void processData() {
		HashMap<String, String> res1;
		String res2 = "";
		System.out.println("-----Dictionary 340 Pro--------");
		while(true){
                System.out.print("Search:  ");
		// Split the entry by using the space, first part is the word second pt is
		// the form of speech or litteral to yield
		String[] lookup = type.nextLine().split(" ");

		boolean k = false;
                boolean z = false;
		if (lookup[0] != null && !lookup[0].isEmpty()) {

			for (Entry<String, HashMap<String, String>> entry : words.entrySet()) {
                            
				String key = entry.getKey();
				if (lookup[0].toLowerCase().equals(key)) {
					res1 = entry.getValue();

					if (lookup.length > 1 && !lookup[1].isEmpty()) {
						//JAVA 8 API, to filter on form of speech
						res2 = res2.concat("|\n"+res1.entrySet().stream().filter(map -> lookup[1].equalsIgnoreCase(map.getValue()))
								.map(map -> map.getKey()).collect(Collectors.joining("\n|\n", "", "")));
						k = true; z = true;

					} else {
						// if no type specified, add all litterals
						for (Entry<String, String> e : res1.entrySet()) {
							res2=res2.concat("\n|\n" + e.getKey());
							k = true; 
						}
					}
					z=false;
					System.out.println(res2);
				}

				
			}
                            if (k == false && z == false) {
				System.out.println("NOT FOUND");
			
			}
		}}

	}

	public static void main(String[] args) {
		Dictionary mydic = new Dictionary();
		// mydic.uploadData();
		mydic.processData();

	}

}
