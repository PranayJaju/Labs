import java.util.*;
class Student
{
	int RegNo;
	String fname;
    short sem;
    GregorianCalendar doj;
    float gpa, cgpa;

    public Student()
    {
    	fname="";
    	RegNo=0;
    	sem=0;
    	gpa=0.0f;
    	cgpa=0.0f;
    	doj=new GregorianCalendar();
    }

    public Student(String fn, short s, int year, int month, int day, float GPA, float CGPA, int sn)
    {
        RegNo=calRegNo(sn, year);
        fname=fn;
        sem=s;
        doj=new GregorianCalendar(year,month,day);
        gpa=GPA;
        cgpa=CGPA;
    }

    public void display()
    {
        System.out.printf("%-25s%-20s\n","Name:",fname);
        if(doj.get(Calendar.YEAR)<2010)
            System.out.printf("%-25s0%-10d\n","Registration Number:", RegNo);
        else 
        	System.out.printf("%-25s%-10d\n","Registration Number:", RegNo);
        System.out.printf("%-25s%-10d\n", "Semester:", sem);
        System.out.printf("%-25s", "Date of Joining:");
        System.out.println(doj.get(Calendar.DATE)+"/"+doj.get(Calendar.MONTH)+"/"+doj.get(Calendar.YEAR));
        System.out.printf("%-25s%-10.2f\n", "GPA:", gpa);
        System.out.printf("%-25s%-10.2f\n", "CGPA:", cgpa);
    }

    public int calRegNo(int stuNo, int year)
    {
        if(stuNo<100)
            RegNo=(year%100)*100+stuNo;
     
        else if(stuNo<1000)
            RegNo=(year%100)*1000+stuNo;

        else if(stuNo<10000)
            RegNo=(year%100)*10000+stuNo;  

        return RegNo;      
    }

    public void Sem_CGPA_Sort(Student s[])
    {
    	for(int i=0; i<s.length; i++)
    	{
    		for(int j=0; j<s.length-i-1; j++)
    		{
    			if(s[j].sem>s[j+1].sem)
    			{
    				Student temp=s[j];
    				s[j]=s[j+1];
    				s[j+1]=temp;
    			}

    			else if(s[j].cgpa>s[j+1].cgpa && s[j].sem==s[j+1].sem)
    			{
    				Student temp=s[j];
    				s[j]=s[j+1];
    				s[j+1]=temp;
    			}
    		}
    	}
    }

    public void Name_Sort(Student s[])
    {
    	for(int i=0; i<s.length; i++)
    	{
    		for(int j=0; j<s.length-1-i; j++)
    		{
    			if((s[j].fname).compareTo(s[j+1].fname)>0)
    			{
    				Student temp=s[j];
    				s[j]=s[j+1];
    				s[j+1]=temp;
    			}
    		}
    	}
    }

    public void Startwith_Char(Student s[], char ch)
    {
    	for(int i=0; i<s.length; i++)
    	{
    		if(s[i].fname.startsWith(String.valueOf(ch)))
    			s[i].display();
    		System.out.println();
    	}
    }

    public void Contains_Sub(Student s[], String sub)
    {
    	for(int i=0; i<s.length; i++)
    	{
    		if(s[i].fname.contains(sub))
    			s[i].display();
    		System.out.println();
    	}
    }

    public void NameChange(Student s[])
    {
        for(int i=0; i<s.length; i++)
        {
            String newName="";
            String individual_name[]=s[i].fname.split(" ");
            for(int j=0; j<individual_name.length; j++)
            {
                if(j==individual_name.length-1)
                    newName=newName+individual_name[j];
                else
                    newName=newName+individual_name[j].charAt(0)+". ";
            }
            s[i].fname=newName;
        }
    }
}

class StudentRecord
{
	public static void main(String args[])
	{
		String na;
		int year, month, day, sn;
		float gpa, cgpa; 
		short sem;
	    Scanner sc=new Scanner(System.in);
	    System.out.println("Enter no.of students.");
	    int n=sc.nextInt();
	    Student s[]=new Student[n];
	    for(int i=0; i<n; i++)
	    {
	    	System.out.println("Enter Name.");
	        sc.nextLine();
	        na=sc.nextLine();
	        System.out.println("Enter Date of Joining.(dd/mm/yyyy)");
	        day=sc.nextInt();
	        month=sc.nextInt();
            year=sc.nextInt();
	        System.out.println("Enter GPA and CGPA.");
	        gpa=sc.nextFloat();
	        cgpa=sc.nextFloat();
	        System.out.println("Enter Semester.");
	        sem=sc.nextShort();
	        System.out.println("Enter Student Number.");
	        sn=sc.nextInt();
	        s[i]=new Student(na, sem, year, month, day, gpa, cgpa, sn);
	    }
        System.out.println();

        System.out.println("*******************************");
	    System.out.println("Sorted according to Semester and CGPA.\n");
	    Student dummy=new Student();
	    dummy.Sem_CGPA_Sort(s);
	    for(int i=0; i<n; i++)
	    {
	    	s[i].display();
	    	System.out.println();
	    }
        
        System.out.println("*******************************");
        System.out.println("Sorted According to Name.\n");
        dummy.Name_Sort(s);
        for(int i=0; i<n; i++)
        {
        	s[i].display();
        	System.out.println();
        }

        System.out.println("*******************************");
        System.out.println("Enter Character to be checked with.");
        char ch=sc.next().charAt(0);
        dummy.Startwith_Char(s, ch);

        System.out.println("*******************************");
        System.out.println("Enter Substring to be checked with.");
        String sub=sc.next();
        dummy.Contains_Sub(s, sub);
        
        System.out.println("*******************************");
        System.out.println("Name Changed to Initials and Family Name.\n");
        dummy.NameChange(s);
        for(int i=0; i<n; i++)
        {
        	s[i].display();
        	System.out.println();
        }
	}
}
