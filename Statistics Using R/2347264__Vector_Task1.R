#1. CREATE A VECTOR NAMED sales_data

sales_data <- c(45,60,35,70,80,62,48,53,69,72,40,55)

#2. CALCULATE TOTAL ANNUAL SALES

total_annual_sales <- sum(sales_data)
print(total_annual_sales)

#3. COMPUTE MONTHLY AVERAGE SALES

monthly_avg_sales <- total_annual_sales/12
print(monthly_avg_sales)

#4. DETERMINE THE MONTH WITH HIGHEST SALES AND THE CORRESPONDING SALES FIGURE.
#   ALSO FIND THE MONTH WITH THE LOWEST SALES AND ITS SALES FIGURE.

#HIGHEST SALES WITH MONTH

highest_sales <- max(sales_data)
print(highest_sales)
order <- order(sales_data)
highest_sales_month <- order[12]
print(highest_sales_month)

#LOWEST SALES WITH MONTH
lowest_sales <- min(sales_data)
print(lowest_sales)
lowest_sales_month <- order[1]
print(lowest_sales_month)


#5 INCREASE THE SALES FIGURE FOR THE THIRD MONTH BY 10%
increment <- sales_data[3] * 0.10
sales_data[3] <- sales_data[3] + increment
print(sales_data[3])


#6. SORT THE sales_data VECTOR IN ASCENDING ORDER AND CREATE A
# NEW VECTOR NAMED sorted_sales.

sorted_sales <- sort(sales_data)
print(sorted_sales)


#7. SORT THE sales_data IN DESCENDING ORDER AND CREATE
#   A NEW VECTOR NAMED reverse_sorted_sales

reverse_sorted_sales <- sort(sales_data,decreasing = TRUE)
print(reverse_sorted_sales)


#8. CALCULATE THE MEDIAN SALES VALUE FROM THE sorted_sales

median_sales_value <- median(sorted_sales)
print(median_sales_value)
