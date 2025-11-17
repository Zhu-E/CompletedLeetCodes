# Write your MySQL query statement below
SELECT project_id, round(AVG(experience_years), 2) as average_years FROM PROJECT LEFT JOIN EMPLOYEE ON PROJECT.employee_id = EMPLOYEE.employee_id group by project_id;
