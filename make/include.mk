INC_CONTAINERS := containers/
# $(addprefix containers/, \
	map/ set/ stack/ vector/)

INC_UTILS := $(addprefix utils/, \
	general/ iter/ pair/ tmp/)

INC = $(addprefix -I src/, $(INC_CONTAINERS) $(INC_UTILS))
