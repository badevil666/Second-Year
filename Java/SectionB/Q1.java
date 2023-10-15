class Employee
{
	String name;
	int age;
	String phoneNo;
	String address;
	String salary;
	Employee(String name, int age, String phoneNo,String address, String salary)
	{
		this.name = name;
		this.age = age;
		this.phoneNo = phoneNo;
		this.address = address;
		this.salary = salary;
	}
	public void printSalary()
	{
		System.out.println("Salary = " + this.salary);
	}
}

class Officer extends Employee
{
	String specialization;
	Officer(String name, int age, String phoneNo,String address, String salary, String specialization)
	{
		super(name, age, phoneNo, address, salary);
		this.specialization = specialization;
	}

}

class Manager extends Employee
{
	String department;
	Manager(String name, int age, String phoneNo,String address, String salary, String department)
	{
		super(name, age, phoneNo, address, salary);
		this.department = department;
	}
}

class Q1
{
	public static void main(String[] args)
	{
		String name = "Tom Cherian";
		int age  = 50;
		String phoneNo = "8590212377";
		String address = "Pala, 12th Mile";
		String salary = "Rs 50000";
		String department = "Sales";
		String specialization = "Debugging";
		Manager m = new Manager(name, age, phoneNo, address, salary, department);
		m.printSalary();
		name = "Alberto Cherian";
		age  = 49;
		phoneNo = "8890212377";
		address = "Pala, 12th Mile";
		salary = "Rs 60000";
		specialization = "Debugging";
		Officer o = new Officer(name, age, phoneNo, address, salary, specialization);
		o.printSalary();

	}


}