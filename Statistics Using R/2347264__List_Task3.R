
# -------LIST OPERATIONS----------

# CREATE LIST NAMED EMPLOYEE

employee <- list(EmployeeID = 1, 
                 Name = "Jack Williams", 
                 Salary = 5000, 
                 Departments = c("DevOps","Frontend")
                )


# DISPLAYING CONTENT OF EMPLOYEE LIST
print(employee)

# employee's annual salary
annual_salary <- 12 * employee$Salary
print(annual_salary)


# Update the employee's name to a different name.

employee$Name <- "Ted"
print(employee)


# Add a new department to the Departments vector for the employee.

employee$Departments <- c(employee$Departments,"Finance","Support")
print(employee)


# Create a list named organization

organization <- list(Name = "Binance", 
                     Employees = list(employee,
                                  list(EmployeeID=2,Name="Peter Dury",Salary=2500, Departments = c("Dev")),
                                  list(EmployeeID=3,Name="Ian",Salary=1900,Departments = c("Support"))))


# Display the entire content of the nested list organization.
print(organization)

# Access and print the annual salary of the second employee in the organization.

annual_salary_2ndEmp <- organization$Employees[[2]]$Salary * 12
print(annual_salary_2ndEmp)


# Access and print the name of the organization.

print(organization$Name)



# Create a new list named department_employees that groups 
# employees by department.Each department should have a
# list of employees associated with it.


department_employees <- list()
for (employee in organization$Employees) {
  departments <- employee$Departments
  for (dept in departments) {
    if (is.null(department_employees[[dept]])) {
      department_employees[[dept]] <- list(employee)
    } else {
      department_employees[[dept]] <- c(department_employees[[dept]], list(employee))
    }
  }
}
print(department_employees) 

