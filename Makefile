CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=gnu++17
NAME := matrix
SRCS := main.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)
OBJ_DIR := build
DEP_DIR := deps
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJS))
DEPS := $(addprefix $(DEP_DIR)/, $(DEPS))
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
all: $(NAME)
$(OBJ_DIR):
	mkdir $@
$(DEP_DIR):
	mkdir $@
$(NAME): $(OBJS) Makefile
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OBJS) -o $@
$(OBJ_DIR)/%.o: %.cpp $(DEP_DIR)/%.d | $(OBJ_DIR) $(DEP_DIR)
	$(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<
$(DEPS): Makefile
-include $(DEPS)
clean:
	$(RM) -rf build/ deps/
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re depend