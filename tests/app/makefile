include prorab.mk

include $(d)../../raspberrypi.mk

this_name := mordatouch-test-app

this_srcs += $(call prorab-src-dir,src)

this_cxxflags += -Wall # enable all warnings
this_cxxflags += -Wno-comment # no warnings on nested comments
this_cxxflags += -Wnon-virtual-dtor # warn if base class has non-virtual destructor
this_cxxflags += -Werror # treat warnings as errors
this_cxxflags += -Wfatal-errors # stop on first error encountered
this_cxxflags += -fstrict-aliasing # in order to comply with the c++ standard more strictly
this_cxxflags += -g # include debugging symbols
this_cxxflags += -std=c++14

this_ldlibs += -lmordavokne-opengles2 -lstdc++ -lmorda -lpuu -rdynamic -lm

this_ldlibs += $(d)../../src/build/libmordatouch.so

this_out_dir := build

ifeq ($(raspberrypi),true)
    this_cxxflags += -I/opt/vc/include
    this_ldflags += -L/opt/vc/lib
    this_ldlibs += -lbrcmGLESv2
else
    this_ldlibs += -lGLESv2
endif

$(eval $(prorab-build-app))

$(prorab_this_name): $(abspath $(d)../../src/build/libmordatouch$(dot_so))

define this_rules = 

    run_app: $(proab_this_name)
$(.RECIPEPREFIX)$(Q)(cd $(d) && LD_LIBRARY_PATH=../../src/build $(prorab_this_name))

endef
$(eval $(this_rules))

$(eval $(call prorab-include, ../../src/makefile))
