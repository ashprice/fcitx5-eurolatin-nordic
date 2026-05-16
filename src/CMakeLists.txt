add_library(eurolatin-nordic SHARED eurolatin-nordic.cpp)
target_link_libraries(eurolatin-nordic PRIVATE Fcitx5::Core)
set_target_properties(eurolatin-nordic PROPERTIES PREFIX "")
install(TARGETS eurolatin-nordic DESTINATION "${FCITX_INSTALL_LIBDIR}/fcitx5")

# Addon config file
# We need an additional layer of conversion because we want PROJECT_VERSION in it.
configure_file(eurolatin-nordic-addon.conf.in eurolatin-nordic-addon.conf)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/eurolatin-nordic-addon.conf" RENAME eurolatin-nordic.conf DESTINATION "${FCITX_INSTALL_PKGDATADIR}/addon")

# Input method registration file
install(FILES "eurolatin-nordic.conf" DESTINATION "${FCITX_INSTALL_PKGDATADIR}/inputmethod")
