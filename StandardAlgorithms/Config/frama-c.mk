
export FRAMAC_SHARE:=$(shell tis-kernel -print-share-path)

export TIMEOUT   ?= 2
export PROCESSES ?= 1

#setup wp
export WP_TIMEOUT        ?= $(TIMEOUT)
export WP_COQ_TIMEOUT    ?= 5
export WP_PROCESSES      ?= $(PROCESSES)

#setup av
export AV_TIMEOUT   ?= $(TIMEOUT)
export AV_PROCESSES ?= $(PROCESSES)

# flags for when we invoke Frama C directly instead of going
# through script_functions.sh
WP_TIME_FLAGS= \
	-wp-timeout $(WP_TIMEOUT) \
	-wp-coq-timeout $(WP_COQ_TIMEOUT) \
	-wp-par $(WP_PROCESSES)

#setup coq
SCRIPT?='$(TOP_DIR)/wp0.script' # default script
DRIVER=$(DRIVER_DIR)/driver

# having this as a separate variable allows us to override it in
# algorithm makefiles
WP_RTE_FLAGS ?= -warn-unsigned-overflow -warn-unsigned-downcast

# We differentiate between two types of WP options:
# 1) in WP_FLAGS we collect the general options
# 2) in WP_PROVER_FLAGS we collect the ones where we select the provers
# This allows us, for example, to start the gui very quickly and then
# run the prover(s) on select proof obligtions.

BASE_FLAGS := -pp-annot
BASE_FLAGS += -no-unicode

WP_BASE_FLAGS := $(BASE_FLAGS)
WP_BASE_FLAGS += -wp
WP_BASE_FLAGS += -wp-rte $(WP_RTE_FLAGS)

AV_BASE_FLAGS := $(BASE_FLAGS)
AV_BASE_FLAGS += -av

WP_FLAGS := $(WP_BASE_FLAGS)
WP_FLAGS += -wp-driver $(DRIVER_DIR)/external.driver
WP_FLAGS += -wp-coq-script $(SCRIPT)
WP_FLAGS += -wp-model Typed

AV_FLAGS     := $(AV_BASE_FLAGS) -av-extract all_annot
AV_WHY3_CONF := $(shell realpath $(TOP_DIR))/astraver.why3.conf

# WP_PROVER_FLAGS += -wp-steps $(WP_ALT_ERGO_STEPS)

# provers
PROVERS ?=""
ifeq ($(PROVERS), alt-ergo)
	WP_PROVER_FLAGS += -wp-prover alt-ergo
else ifeq ($(PROVERS), coq)
	WP_PROVER_FLAGS += -wp-prover native:coq
else ifeq ($(PROVERS), cvc4)
	WP_PROVER_FLAGS += -wp-prover cvc4
else ifeq ($(PROVERS), cvc3)
	WP_PROVER_FLAGS += -wp-prover cvc3
else ifeq ($(PROVERS), z3)
	WP_PROVER_FLAGS += -wp-prover z3
else ifeq ($(PROVERS), eprover)
	WP_PROVER_FLAGS += -wp-prover eprover
else ifneq ($(PROVERS),)
@echo "Prover unknown. Continue using default provers:"
PROVERS = alt-ergo cvc4 cvc3 z3 
WP_PROVER_FLAGS += $(addprefix -wp-prover , $(PROVERS))
WP_PROVER_FLAGS += -wp-prover native:coq
endif

export FR    := frama-c
export FRGUI := frama-c-gui

export WP_PROVER_FLAGS
export WP_C_FLAGS   = -cpp-extra-args="$(INCLUDES)" $(WP_FLAGS)
export WP_CXX_FLAGS = -cxx-clang-command="framaCIRGen $(INCLUDES)"  $(WP_FLAGS)
export WP_C_REPORT  = $(FR) $(WP_C_FLAGS) $(WP_PROVER_FLAGS) -wp-par $(WP_PROCESSES)

export AV_C_FLAGS  = -cpp-extra-args="$(INCLUDES)" $(AV_FLAGS)
export AV_STRATEGY = acslbyexample
export AV_C_REPORT = $(FR) $(AV_C_FLAGS) -av-target why3sprove -av-why3-opt " --extra-config $(AV_WHY3_CONF) --no-save-session --strategy $(AV_STRATEGY) "

