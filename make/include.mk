INC_CONTAINERS := $(addprefix containers/, \
	map/ set/ stack/ vector/)

INC_UTILS := $(addprefix utils/, \
	general/ iterator/ pair/ tmp/)

INC = $(addprefix -I src/, $(INC_CONTAINERS) $(INC_UTILS))
