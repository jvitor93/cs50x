SELECT DISTINCT title FROM movies JOIN  stars ON movies.id = stars.movie_id
JOIN people ON people.id =  stars.person_id
WHERE name = 'Johnny Depp'
INTERSECT
SELECT DISTINCT title FROM movies JOIN  stars ON movies.id = stars.movie_id
JOIN people ON people.id =  stars.person_id
WHERE name = 'Helena Bonham Carter';