name = PhoneBook
FLAGS = -Wall -Wextra -Werror -std=c++98
CP = c++
srcs = PhoneBook.cpp Contact.cpp main.cpp
heads = Contact.hpp PhoneBook.hpp
objs = ${srcs:.cpp=.o}
RM = rm -f

all: $(name)

%.o: %.cpp $(heads)
	$(CP) $(FLAGS) -c $< -o $@

$(name): $(objs)
	$(CP) $(FLAGS) $(objs) -o $(name)

clean:
	$(RM) $(objs)

fclean: clean
	$(RM) $(name)

re: fclean all