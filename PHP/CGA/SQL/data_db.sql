/*

10000 - user
20000 - student
30000 - ta
40000 - professor
50000 - course
60000 - section
70000 - groups
80000 - task
90000 - solution

1100000 - announcement
2200000 - forum
3300000 - reply
4400000 - discussion
5500000 - comment
6600000 - files
7700000 - grades
8800000 - messages

*/

INSERT INTO roles (role_name, role_description) VALUES
("Admin", "CGA Admin"),
("Professor", "Course Instructor"),
("TA", "Course Assistant"),
("Student", "Course Student");

INSERT INTO users (first_name, last_name, dob, email, username, password, created_on, first_login, role_id) VALUES 
("Admin", "CGA","1980-01-01", "admin@admin.com", "admin", "admin", CURRENT_TIMESTAMP, 1, 1),
("Albert", "Einstein","1900-01-01", "albert@einstein.com", "a_einstein_2", "12345", CURRENT_TIMESTAMP, 1, 2),
("Issac", "Newton","1900-01-01", "issac@pnewton.com", "i_newton_2", "12345", CURRENT_TIMESTAMP, 1, 2),
("Nikola", "Tesla","1900-01-01", "nikola@tesla.com", "n_tesla_2", "12345", CURRENT_TIMESTAMP, 1, 2),
("Steve", "Jobs","1980-01-01", "steve@jobs.com", "s_jobs_3", "12345", CURRENT_TIMESTAMP, 1, 3),
("Bill", "Gates","1980-01-01", "bill@gates.com", "b_gates_3", "12345", CURRENT_TIMESTAMP, 1, 3),
("Elon", "Musk","1980-01-01", "elon@musk.com", "e_musk_3", "12345", CURRENT_TIMESTAMP, 1, 3),
("John", "Doe","1990-01-01", "john@doe.com", "j_doe_4", "12345", CURRENT_TIMESTAMP,1, 4),
("Mary", "Jane","1990-01-01", "mary@jane.com", "m_jane_4", "12345", CURRENT_TIMESTAMP,1, 4),
("Tony", "Stark","1980-01-01", "tony@stark.com", "t_stark_4", "12345", CURRENT_TIMESTAMP,1, 4),
("Bruce", "Wayne","1990-01-01", "bruce@wayne.com", "b_wayne_4", "12345", CURRENT_TIMESTAMP,1, 4),
("Peter", "Parker","1990-01-01", "peter@parker.com", "p_parker_4", "12345", CURRENT_TIMESTAMP,1, 4),
("Clark", "Kent","1980-01-01", "clark@kent.com", "c_kent_4", "12345", CURRENT_TIMESTAMP,1, 4);

-- Professor Table
INSERT INTO professor (user_id) VALUES
(10001), (10002), (10003);
-- TA Table
INSERT INTO ta (user_id) VALUES
(10004), (10005), (10006);
-- Student Table
INSERT INTO student (user_id) VALUES
(10007), (10008), (10009), (10010), (10011), (10012);

INSERT INTO course (course_name, course_number) VALUES
("Files and DB", 5531),
("Operating Systems", 5461),
("Tools and Techniques", 5541);

-- Course Section Table
INSERT INTO section (section_name, course_id) VALUES
("AdbA", 50000),
("BdbB", 50000),
("AosA", 50001),
("BosB", 50001),
("CtoolsC", 50002),
("DtoolsD", 50002);