SELECT * FROM users as u
JOIN student as st ON st.user_id = u.user_id
JOIN user_course_section as ucs ON ucs.user_id = u.user_id
JOIN course as c ON c.course_id = ucs.course_id
JOIN section as s ON s.section_id = ucs.section_id
ORDER BY u.user_id ASC;

SELECT d.*, u.username, g.group_name, c.course_name FROM discussion as d
JOIN users as u ON d.posted_by_uid = u.user_id
JOIN student_group as g ON g.group_id = d.group_id
JOIN group_of_course as gc ON gc.group_id = g.group_id
JOIN course as c ON c.course_id = gc.course_id
ORDER BY discussion_id ASC;

SELECT * FROM student_group as g
JOIN group_of_course as gc ON gc.group_id = g.group_id
JOIN course as c ON c.course_id = gc.course_id;

SELECT * FROM student_group as g
JOIN student as s ON g.group_leader_sid = s.student_id
JOIN users as u ON s.user_id = u.user_id
JOIN group_of_course as gc ON gc.group_id = g.group_id
JOIN course as c ON c.course_id = gc.course_id
ORDER BY g.group_id ASC;

SELECT * FROM users as u
JOIN user_course_section as ucs ON ucs.user_id = u.user_id
JOIN course as c ON c.course_id = ucs.course_id
LEFT JOIN section as s ON s.section_id = ucs.section_id
ORDER BY u.user_id ASC;

SELECT * FROM users as u
JOIN student as st ON st.user_id = u.user_id
JOIN member_of_group as mg ON mg.student_id = st.student_id
JOIN student_group as g ON g.group_id = mg.group_id
JOIN group_of_course as gc ON gc.group_id = g.group_id
JOIN user_course_section as ucs ON ucs.user_id = u.user_id
JOIN course as c ON c.course_id = ucs.course_id
JOIN section as s ON s.section_id = ucs.section_id
ORDER BY u.user_id ASC;

SELECT * FROM announcement as a
JOIN users as u ON a.posted_by_uid = u.user_id
JOIN course as c ON c.course_id = a.course_id
ORDER BY a.announcement_id DESC;

SELECT g.*, u.*, c.section_name, c.course_name
FROM student_group as g
JOIN member_of_group as mg ON mg.group_id = g.group_id
JOIN group_of_course as gc ON gc.group_id = g.group_id
JOIN student as st ON st.student_id = mg.student_id
JOIN users as u ON u.user_id = s.user_id
JOIN user_course_section as ucs ON ucs.user_id = u.user_id
JOIN course as c ON c.course_id = ucs.course_id,
JOIN section as s ON s.section_id = ucs.section_id,
ORDER BY g.group_id ASC;