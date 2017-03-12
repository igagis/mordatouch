include prorab.mk

include $(d)raspberrypi.mk

this_name := mordatouch

this_srcs += $(call prorab-src-dir,src)

this_cxxflags += -Wall #enable all warnings
this_cxxflags += -Wno-comment #no warnings on nested comments
this_cxxflags += -funsigned-char #the 'char' type is unsigned
this_cxxflags += -Wnon-virtual-dtor #warn if base class has non-virtual destructor
this_cxxflags += -fno-operator-names #do not treat 'and', 'bitand','bitor','compl','not','or','xor' as keywords
this_cxxflags += -Werror #treat warnings as errors
this_cxxflags += -Wfatal-errors # stop on first error encountered
this_cxxflags += -fstrict-aliasing #strict aliasing (in order to comply with the c++ standard more strictly)
this_cxxflags += -g #include debugging symbols
this_cxxflags += -std=c++11

ifeq ($(raspberrypi),true)
    this_cxxflags += -I/opt/vc/include
    this_ldflags += -L/opt/vc/lib
endif

this_ldlibs += -lmordavokne-opengles2 -lstdc++ -lmorda -lstob -lGLESv2 -rdynamic -lm

$(eval $(prorab-build-app))
