create database cga;
use cga;

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

CREATE TABLE roles
(
  role_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  role_name VARCHAR(30) NOT NULL UNIQUE,
  role_description VARCHAR(255) NOT NULL
);
ALTER TABLE roles AUTO_INCREMENT = 1;


CREATE TABLE users
(
  user_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  first_name VARCHAR(30) NOT NULL,
  last_name VARCHAR(30) NOT NULL,
  dob DATE NOT NULL,
  email VARCHAR(30) NOT NULL UNIQUE,
  username VARCHAR(30) NOT NULL UNIQUE,
  password VARCHAR(30) NOT NULL,
  created_on DATETIME DEFAULT CURRENT_TIMESTAMP,
  first_login TINYINT NOT NULL,
  role_id INT NOT NULL,
  FOREIGN KEY (role_id) REFERENCES roles(role_id)
);
ALTER TABLE users AUTO_INCREMENT = 10000;


CREATE TABLE student
(
  student_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  user_id INT NOT NULL,
  FOREIGN KEY (user_id) REFERENCES users(user_id)
);
ALTER TABLE student AUTO_INCREMENT = 20000;


CREATE TABLE ta
(
  ta_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  user_id INT NOT NULL,
  FOREIGN KEY (user_id) REFERENCES users(user_id)
);
ALTER TABLE ta AUTO_INCREMENT = 30000;


CREATE TABLE professor
(
  professor_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  user_id INT NOT NULL,
  FOREIGN KEY (user_id) REFERENCES users(user_id)
);
ALTER TABLE professor AUTO_INCREMENT = 40000;


CREATE TABLE course
(
  course_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  course_name VARCHAR(30) NOT NULL UNIQUE,
  course_number INT NOT NULL UNIQUE
);
ALTER TABLE course AUTO_INCREMENT = 50000;


CREATE TABLE section
(
  section_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  section_name VARCHAR(30) NOT NULL,
  course_id INT NOT NULL,
  FOREIGN KEY (course_id) REFERENCES course(course_id)
);
ALTER TABLE section AUTO_INCREMENT = 60000;


CREATE TABLE student_groups
(
  group_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  group_name VARCHAR(30) NOT NULL,
  group_leader_sid INT NOT NULL
);
ALTER TABLE student_groups AUTO_INCREMENT = 70000;


CREATE TABLE files
(
  file_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  file_name VARCHAR(30) NOT NULL,
  file_content VARCHAR(255) NOT NULL,
  file_type VARCHAR(30) NOT NULL,
  file_size INT NOT NULL,
  uploaded_by_uid INT NOT NULL,
  uploaded_on DATETIME DEFAULT CURRENT_TIMESTAMP
);
ALTER TABLE files AUTO_INCREMENT = 6600000;

CREATE TABLE task
(
  task_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  task_type VARCHAR(30) NOT NULL,
  task_content VARCHAR(255) NOT NULL UNIQUE,
  task_deadline DATETIME NOT NULL,
  file_id INT NOT NULL,
  course_id INT NOT NULL,
  FOREIGN KEY (file_id) REFERENCES files(file_id),
  FOREIGN KEY (course_id) REFERENCES course(course_id)
);
ALTER TABLE task AUTO_INCREMENT = 80000;


CREATE TABLE solution
(
  solution_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  solution_type VARCHAR(30) NOT NULL,
  solution_content VARCHAR(255) NOT NULL UNIQUE,
  task_id INT NOT NULL,
  group_id INT NOT NULL,
  file_id INT NOT NULL,
  FOREIGN KEY (task_id) REFERENCES task(task_id),
  FOREIGN KEY (group_id) REFERENCES student_groups(group_id),
  FOREIGN KEY (file_id) REFERENCES files(file_id)
);
ALTER TABLE solution AUTO_INCREMENT = 90000;

CREATE TABLE grades
(
  grade_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  grade INT NOT NULL,
  student_id INT NOT NULL,
  solution_id INT NOT NULL,
  FOREIGN KEY (student_id) REFERENCES student(student_id),
  FOREIGN KEY (solution_id) REFERENCES solution(solution_id),
  UNIQUE (student_id, solution_id) 
);
ALTER TABLE grades AUTO_INCREMENT = 7700000;

CREATE TABLE announcement
(
  announcement_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  announcement_title VARCHAR(255) NOT NULL,
  announcement_content VARCHAR(1024) NOT NULL,
  posted_by_uid INT NOT NULL,
  posted_on DATETIME DEFAULT CURRENT_TIMESTAMP,
  course_id INT NOT NULL,
  FOREIGN KEY (course_id) REFERENCES course(course_id) ON DELETE CASCADE ON UPDATE CASCADE
);
ALTER TABLE announcement AUTO_INCREMENT = 1100000;

CREATE TABLE forum
(
  forum_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  forum_title VARCHAR(30) NOT NULL,
  forum_content VARCHAR(1024) NOT NULL,
  posted_by_uid INT NOT NULL,
  posted_on DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,
  course_id INT NOT NULL,
  file_id INT,
  FOREIGN KEY (course_id) REFERENCES course(course_id) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (file_id) REFERENCES files(file_id) ON DELETE CASCADE ON UPDATE CASCADE
);
ALTER TABLE forum AUTO_INCREMENT = 2200000;


CREATE TABLE reply
(
  reply_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  reply_content VARCHAR(1024) NOT NULL,
  posted_by_uid INT NOT NULL,
  posted_on DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,
  forum_id INT NOT NULL,
  file_id INT,
  FOREIGN KEY (forum_id) REFERENCES forum(forum_id) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (file_id) REFERENCES files(file_id) ON DELETE CASCADE ON UPDATE CASCADE
);
ALTER TABLE reply AUTO_INCREMENT = 3300000;


CREATE TABLE discussion
(
  discussion_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  discussion_title VARCHAR(30) NOT NULL,
  discussion_content VARCHAR(1024) NOT NULL,
  posted_by_uid INT NOT NULL,
  posted_on DATETIME DEFAULT CURRENT_TIMESTAMP,
  group_id INT,
  task_id INT,
  file_id INT,
  FOREIGN KEY (group_id) REFERENCES student_groups(group_id) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (task_id) REFERENCES task(task_id) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (file_id) REFERENCES files(file_id) ON DELETE CASCADE ON UPDATE CASCADE
);
ALTER TABLE discussion AUTO_INCREMENT = 4400000;


CREATE TABLE comment
(
  comment_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  comment_content VARCHAR(1024) NOT NULL,
  posted_by_uid INT NOT NULL,
  posted_on DATETIME DEFAULT CURRENT_TIMESTAMP,
  discussion_id INT NOT NULL,
  file_id INT,
  FOREIGN KEY (discussion_id) REFERENCES discussion(discussion_id) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (file_id) REFERENCES files(file_id) ON DELETE CASCADE ON UPDATE CASCADE
);
ALTER TABLE comment AUTO_INCREMENT = 5500000;

CREATE TABLE messages
(
  message_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  message_content VARCHAR(1024) NOT NULL,
  message_date DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,
  sender_user_id INT NOT NULL,
  receiver_user_id INT NOT NULL,
  file_id INT,
  FOREIGN KEY (sender_user_id) REFERENCES users(user_id),
  FOREIGN KEY (receiver_user_id) REFERENCES users(user_id),
  FOREIGN KEY (file_id) REFERENCES files(file_id)
);
ALTER TABLE messages AUTO_INCREMENT = 8800000;

-- ------------------------------------------------------------------

CREATE TABLE member_of_group
(
  student_id INT NOT NULL,
  group_id INT NOT NULL,
  FOREIGN KEY (student_id) REFERENCES student(student_id) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (group_id) REFERENCES student_groups(group_id) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE ta_of_section
(
  ta_id INT NOT NULL,
  section_id INT NOT NULL,
  FOREIGN KEY (ta_id) REFERENCES ta(ta_id) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (section_id) REFERENCES section(section_id)ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE prof_of_course
(
  professor_id INT NOT NULL,
  course_id INT NOT NULL,
  FOREIGN KEY (professor_id) REFERENCES professor(professor_id) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (course_id) REFERENCES course(course_id) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE group_of_course
(
  group_id INT NOT NULL,
  course_id INT NOT NULL,
  FOREIGN KEY (group_id) REFERENCES student_groups(group_id) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (course_id) REFERENCES course(course_id) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE user_course_section
(
  user_id INT NOT NULL,
  course_id INT NOT NULL,
  section_id INT,
  FOREIGN KEY (user_id) REFERENCES users(user_id) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (course_id) REFERENCES course(course_id) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (section_id) REFERENCES section(section_id) ON DELETE CASCADE ON UPDATE CASCADE,
  UNIQUE (user_id, section_id)
);