-- Keep a log of any SQL queries you execute as you solve the mystery.
-- ran the query .tables so that I can start off by seeing all the tables that are in the database so I can know where I can look

-- ran .schema crime_scene_reports so that I could see the different fields in the crime scene reports table

-- ran query SELECT description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND year = 2021;
-- This allowed me to get a description of the crime scene that happened on that day I learnt there was 3 witnesses interviewed and that
-- the crime took place at 10:15 am at Humphrey Street bakery.

-- .schema bakery_security_logs so that I could get a better understanding of the table
-- .schema interviews to also get a better understanding of the table and understand what I want to do next

-- SELECT name, transcript FROM interviews WHERE day = 28 AND year = 2021 AND month = 7; so that I could see the interviews that happened on that place
-- This allowed me to determine which interviews were from the related crime and then learn about the crime
-- I leart from Ruth that within 10 minutes the theif got into a car and drove away so I should look for cars leaving around 10:25 am
-- From Eugene I learnt that the thief withdrew money from the ATM on Leggett Street early that day
-- I learn from Raymond the thief called someone for less than a minute before they left the bakery and this accomplice bought the ticket

-- ran the query select license_plate, activity from bakery_security_logs where day = 28 AND month = 7 AND year = 2021 AND hour = 10 AND minute LIKE 20;
-- THis allowed me to find the license plate of the car that left with the thief in it which was G412CB7

--SELECT caller, receiver, duration FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;
-- This has allwoed me to find all the potential phone calls that may have been between the theif and his accomplice
-- +----------------+----------------+----------+
--|     caller     |    receiver    | duration |
--+----------------+----------------+----------+
--| (130) 555-0289 | (996) 555-8899 | 51       |
--| (499) 555-9472 | (892) 555-8872 | 36       |
--| (367) 555-5533 | (375) 555-8161 | 45       |
--| (499) 555-9472 | (717) 555-1342 | 50       |
--| (286) 555-6063 | (676) 555-6554 | 43       |
--| (770) 555-1861 | (725) 555-3243 | 49       |
--| (031) 555-6622 | (910) 555-3251 | 38       |
--| (826) 555-1652 | (066) 555-9701 | 55       |
--| (338) 555-6650 | (704) 555-2131 | 54       |
--+----------------+----------------+----------+

-- Thief arrived to bakery at 9:28 am

-- select account_number from atm_transactions
-- where year = 2021 AND day = 28 AND month = 7 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
--Gave me the potential account_numbers of the thief
--+----------------+
--| account_number |
--+----------------+
--| 28500762       |
--| 28296815       |
--| 76054385       |
--| 49610011       |
--| 16153065       |
--| 25506511       |
--| 81061156       |
--| 26013199       |
--+----------------+

--SELECT * FROM people WHERE license_plate = "G412CB7";

--SELECT * FROM people WHERE phone_number = "(996) 555-8899";
-- Now I know the potential accomplices

--SELECT flight_id FROM passengers WHERE passport_number = 1695452385;
--I now know that the flight_id they was on was 36

--SELECT destination_airport_id, day, month, year FROM flights WHERE id = 36;
-- Now I know that the airport id they landed at was 4 and have checked that the date is correct
--Now I can check which city that airport is in.

--SELECT city FROM airports WHERE id = 4;
--The city was New York City