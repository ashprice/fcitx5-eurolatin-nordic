#include "eurolatin-nordic.hpp"

#include <fcitx/inputpanel.h>
#include <fcitx/instance.h>

std::optional<std::string> getCHARForNOR(std::string baseCharacter,
    fcitx::KeySym norModifier)
{
  if (baseCharacter == "backslash") {
    if (norModifier == FcitxKey_d) return "ð";
    if (norModifier == FcitxKey_D) return "Ð";
    if (norModifier == FcitxKey_o) return "ø";
    if (norModifier == FcitxKey_O) return "Ø";
    if (norModifier == FcitxKey_a) return "æ";
    if (norModifier == FcitxKey_A) return "Æ";
  }
  if (baseCharacter == "equal") {
    if (norModifier == FcitxKey_t) return "þ";
    if (norModifier == FcitxKey_T) return "Þ";
  }
  if (baseCharacter == "comma") {
    if (norModifier == FcitxKey_e) return "ę";
    if (norModifier == FcitxKey_E) return "Ę";
    if (norModifier == FcitxKey_o) return "ǫ";
    if (norModifier == FcitxKey_O) return "Ǫ";
    if (norModifier == FcitxKey_c) return "ç";
    if (norModifier == FcitxKey_C) return "Ç";
  }
  if (baseCharacter == "at") {
    if (norModifier == FcitxKey_a) return "å";
    if (norModifier == FcitxKey_A) return "Å";
  }
  if (baseCharacter == "colon") {
    if (norModifier == FcitxKey_a) return "ä";
    if (norModifier == FcitxKey_A) return "Ä";
    if (norModifier == FcitxKey_o) return "ö";
    if (norModifier == FcitxKey_O) return "Ö";
    if (norModifier == FcitxKey_u) return "ü";
    if (norModifier == FcitxKey_U) return "Ü";
  }
  if (baseCharacter == "grave") {
    if (norModifier == FcitxKey_o) return "ò";
    if (norModifier == FcitxKey_O) return "Ò";
    if (norModifier == FcitxKey_e) return "è";
    if (norModifier == FcitxKey_E) return "È";
    if (norModifier == FcitxKey_a) return "à";
    if (norModifier == FcitxKey_A) return "À";
  }
  if (baseCharacter == "apostrophe") {
    if (norModifier == FcitxKey_a) return "á";
    if (norModifier == FcitxKey_A) return "Á";
    if (norModifier == FcitxKey_e) return "é";
    if (norModifier == FcitxKey_E) return "É";
    if (norModifier == FcitxKey_i) return "í";
    if (norModifier == FcitxKey_I) return "Í";
    if (norModifier == FcitxKey_o) return "ó";
    if (norModifier == FcitxKey_O) return "Ó";
    if (norModifier == FcitxKey_u) return "ú";
    if (norModifier == FcitxKey_U) return "Ú";
    if (norModifier == FcitxKey_y) return "ý";
    if (norModifier == FcitxKey_Y) return "Ý";
  }
  if (baseCharacter == "less") {
    if (norModifier == FcitxKey_less) return "«";
  }
  if (baseCharacter == "greater") {
    if (norModifier == FcitxKey_greater) return "»";
  }
  if (baseCharacter == "asciicircum") {
    if (norModifier == FcitxKey_e) return "ê";
    if (norModifier == FcitxKey_E) return "Ê";
    if (norModifier == FcitxKey_o) return "ô";
    if (norModifier == FcitxKey_O) return "Ô";
  }

  return {};
}

/* the lazy way became the hard way */

bool isSpecialNORModifier(fcitx::KeySym key)
{
  return key == FcitxKey_backslash || key == FcitxKey_equal ||
    key == FcitxKey_comma || key == FcitxKey_at ||
    key == FcitxKey_colon || key == FcitxKey_grave ||
    key == FcitxKey_apostrophe || key == FcitxKey_less ||
    key == FcitxKey_greater;
}

bool isNORModifier(fcitx::KeySym key)
{
  return key == FcitxKey_A || key == FcitxKey_a ||
    key == FcitxKey_B || key == FcitxKey_b ||
    key == FcitxKey_C || key == FcitxKey_c ||
    key == FcitxKey_D || key == FcitxKey_d ||
    key == FcitxKey_E || key == FcitxKey_e ||
    key == FcitxKey_F || key == FcitxKey_f ||
    key == FcitxKey_G || key == FcitxKey_g ||
    key == FcitxKey_H || key == FcitxKey_h ||
    key == FcitxKey_I || key == FcitxKey_i ||
    key == FcitxKey_J || key == FcitxKey_j ||
    key == FcitxKey_K || key == FcitxKey_k ||
    key == FcitxKey_L || key == FcitxKey_l ||
    key == FcitxKey_M || key == FcitxKey_m ||
    key == FcitxKey_N || key == FcitxKey_n ||
    key == FcitxKey_O || key == FcitxKey_o ||
    key == FcitxKey_P || key == FcitxKey_p ||
    key == FcitxKey_Q || key == FcitxKey_q ||
    key == FcitxKey_R || key == FcitxKey_r ||
    key == FcitxKey_S || key == FcitxKey_s ||
    key == FcitxKey_T || key == FcitxKey_t ||
    key == FcitxKey_U || key == FcitxKey_u ||
    key == FcitxKey_V || key == FcitxKey_v ||
    key == FcitxKey_W || key == FcitxKey_w ||
    key == FcitxKey_X || key == FcitxKey_x ||
    key == FcitxKey_Y || key == FcitxKey_y ||
    key == FcitxKey_Z || key == FcitxKey_z ||
    key == FcitxKey_less || key == FcitxKey_greater;
}

bool isTriPrefix(fcitx::KeySym key)
{
  return key == FcitxKey_a || key == FcitxKey_A;
}

bool isTriMid(fcitx::KeySym key)
{
  return key == FcitxKey_backslash;
}

bool isTriFinal(fcitx::KeySym key)
{
  return key == FcitxKey_e || key == FcitxKey_E ||
    key == FcitxKey_d || key == FcitxKey_D;
}

/* probably the below logic can be simplified in some way, but I am dumb */

void NORState::handleAlphaKey(fcitx::Key key)
	{

    if (isTriPrefix(key.sym()) && !m_lastKey.has_value()) {
      m_lastKey = key.toString();
      m_buffer.type(key.sym());
      return;
    }

    if (isTriPrefix(key.sym()) && m_lastKey.has_value()) {
      if (m_lastKey == "a") {
        m_buffer.type(key.sym());
        m_lastKey = key.toString();
        return;
      } else if (m_lastKey == "A") {
        m_buffer.type(key.sym());
        m_lastKey = key.toString();
        return;
      }
    }

    if (isTriMid(key.sym()) && m_lastKey.has_value()) {
      if (m_lastKey == "a") {
        m_lastKey = "abackslash";
        m_buffer.type(key.sym());
        return;
      } else if (m_lastKey == "A") {
        m_lastKey = "Abackslash";
        m_buffer.type(key.sym());
        return;
      }
    }

    if (isTriFinal(key.sym()) && m_lastKey.has_value()) {
      if (m_lastKey == "abackslash" && key.sym() == FcitxKey_e) {
        m_buffer.backspace();
        m_buffer.backspace();
				m_buffer.type("æ");
        m_ic->commitString(m_buffer.userInput());
        m_buffer.clear();
        updateUI();
        m_lastKey.reset();
        return;
      } else if (m_lastKey == "Abackslash" && key.sym() == FcitxKey_E) {
        m_buffer.backspace();
        m_buffer.backspace();
        m_buffer.type("Æ");
        m_ic->commitString(m_buffer.userInput());
        m_buffer.clear();
        updateUI();
        m_lastKey.reset();
        return;
      } else if (m_lastKey == "abackslash" && key.sym() == FcitxKey_d) {
        m_buffer.backspace();
        m_buffer.type("ð");
        m_ic->commitString(m_buffer.userInput());
        m_buffer.clear();
        updateUI();
        m_lastKey.reset();
        return;
      } else if (m_lastKey == "abackslash" && key.sym() == FcitxKey_D) {
        m_buffer.backspace();
        m_buffer.type("Ð");
        m_ic->commitString(m_buffer.userInput());
        m_buffer.clear();
        updateUI();
        m_lastKey.reset();
        return;
      } else if (m_lastKey == "Abackslash" && key.sym() == FcitxKey_d) {
        m_buffer.backspace();
        m_buffer.type("ð");
        m_ic->commitString(m_buffer.userInput());
        m_buffer.clear();
        updateUI();
        m_lastKey.reset();
        return;
      } else if (m_lastKey == "Abackslash" && key.sym() == FcitxKey_D) {
        m_buffer.backspace();
        m_buffer.type("Ð");
        m_ic->commitString(m_buffer.userInput());
        m_buffer.clear();
        updateUI();
        m_lastKey.reset();
        return;
      }
    }

		if (!isNORModifier(key.sym()) && !m_lastKey.has_value()) {
      m_lastKey = key.toString();
			m_buffer.type(key.sym());
      return;
		}

    if (!isNORModifier(key.sym()) && m_lastKey.has_value()) {
      if (key.toString() == m_lastKey) {
        m_lastKey.reset();
        m_ic->commitString(m_buffer.userInput());
        m_buffer.clear();
        updateUI();
        return;
      } else {
        m_ic->commitString(m_buffer.userInput());
        m_buffer.clear();
        m_lastKey = key.toString();
        m_buffer.type(key.sym());
        return;
      }
    }

    if (isSpecialNORModifier(key.sym()) && m_lastKey.has_value() && (m_lastKey != "greater" && m_lastKey != "less")) {
      if (key.toString() == m_lastKey) {
        m_ic->commitString(m_buffer.userInput());
        m_buffer.clear();
        m_lastKey.reset();
        return;
      }
    }

    if (isNORModifier(key.sym()) && !isSpecialNORModifier(key.sym()) && !m_lastKey.has_value()) {
      m_buffer.type(key.sym());
      m_ic->commitString(m_buffer.userInput());
      m_buffer.clear();
      updateUI();
      return;
    }

    if (isNORModifier(key.sym()) && isSpecialNORModifier(key.sym()) && !m_lastKey.has_value()) {
      m_lastKey = key.toString();
			m_buffer.type(key.sym());
      return;
    }

		if (isNORModifier(key.sym()) && m_lastKey.has_value()) {
			auto eurChar = getCHARForNOR(*m_lastKey, key.sym());
			if (eurChar) {
        m_buffer.backspace();
				m_buffer.type(*eurChar);
        m_ic->commitString(m_buffer.userInput());
        m_buffer.clear();
        updateUI();
			} else {
        m_buffer.type(key.sym());
        m_ic->commitString(m_buffer.userInput());
        m_buffer.clear();
        updateUI();
      }
      m_lastKey.reset();
		}
	}


void NORState::keyEvent(fcitx::KeyEvent& keyEvent)
{
  if (m_buffer.empty() && !keyEvent.key().isSimple()) return;

  if (keyEvent.key().check(FcitxKey_Return)) {
    m_ic->commitString(m_buffer.userInput());
    reset();
  } else if (keyEvent.key().check(FcitxKey_space)) {
    m_ic->commitString(m_buffer.userInput());
    m_ic->commitString(" ");
    m_lastKey.reset();
    reset();
  } else if (keyEvent.key().check(FcitxKey_BackSpace)) {
    m_buffer.backspace();
  } else if (keyEvent.key().isSimple()) {
    handleAlphaKey(keyEvent.key());
  }
  updateUI();
  keyEvent.filterAndAccept();
}

void NORState::updateUI()
{
  auto& inputPanel = m_ic->inputPanel();
  inputPanel.reset();
  if (m_ic->capabilityFlags().test(fcitx::CapabilityFlag::Preedit)) {
    fcitx::Text preedit(m_buffer.userInput(),
        fcitx::TextFormatFlag::HighLight);
    inputPanel.setClientPreedit(preedit);
  } else {
    fcitx::Text preedit(m_buffer.userInput());
    inputPanel.setPreedit(preedit);
  }
  m_ic->updateUserInterface(fcitx::UserInterfaceComponent::InputPanel);
  m_ic->updatePreedit();
}

NOREngine::NOREngine(fcitx::Instance* instance)
  : m_factory(
      [this](fcitx::InputContext& ic) { return new NORState(this, &ic); })
{
  instance->inputContextManager().registerProperty("norState", &m_factory);
}

void NOREngine::keyEvent(const fcitx::InputMethodEntry&,
    fcitx::KeyEvent& keyEvent)
{
  if (keyEvent.isRelease() || keyEvent.key().states()) {
    return;
  }

  auto ic = keyEvent.inputContext();
  auto* state = ic->propertyFor(&m_factory);
  state->keyEvent(keyEvent);
}

void NOREngine::reset(const fcitx::InputMethodEntry&,
    fcitx::InputContextEvent& event)
{
  auto* state = event.inputContext()->propertyFor(&m_factory);
  state->reset();
}

FCITX_ADDON_FACTORY(NOREngineFactory);
